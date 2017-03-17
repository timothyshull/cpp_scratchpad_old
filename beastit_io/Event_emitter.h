#ifndef BEASTIT_IO_EVENT_EMITTER_H
#define BEASTIT_IO_EVENT_EMITTER_H

#include <cstddef>
#include <iostream>
#include <vector>
#include "Event_handlers.h"
// #include "Handler.h"

class Handler;

enum class Events_error_states {
    null
};

enum class Domain {
    none,
    active
};

class Event_emitter {
public:
    Event_emitter()
            : domain{using_domains ? Domain::active : Domain::none},
              _events{},
              _events_count{0} {}

    inline std::size_t get_default_max_listeners() const noexcept { return default_max_listeners; }

    void set_default_max_listeners(std::size_t max_listeners)
    {
        std::clog << max_listeners << "\n";
        default_max_listeners = max_listeners;
    }

    Event_emitter& set_max_listeners(unsigned max_listeners)
    {
        *_max_listeners = max_listeners;
        return *this;
    }

    bool emit(std::string& type)
    {
        bool need_domain_exit{false};
        bool do_error{type == "error"};

        Event_handlers events{_events};
        if (events) { do_error = (do_error && events.error() == Events_error_states::null); }
        else if (!do_error) { return false; }

        Domain domain{this->domain};

        if (do_error) {
            // TODO: custom exception types here
            return false;
        }

        Handler handler{events[type]};

        if (!handler) {
            return false;
        }

        if (domain) {
            domain.enter();
            need_domain_exit = true;
        }

        bool is_fn{std::is_function<decltype(handler)>::value};
        // TODO: emit template with Args...
        if (need_domain_exit) {
            domain.exit();
        }

        return true;
    }

private:
    static const bool using_domains = false;
    static std::size_t default_max_listeners = 10;
    Domain domain;
    Event_handlers _events;
    std::size_t _events_count;
    std::size_t* _max_listeners = nullptr;

    friend std::size_t $get_max_listeners(Event_emitter* that);
};

std::size_t $get_max_listeners(Event_emitter* that)
{
    if (that && that->_max_listeners == nullptr || !that) {
        return Event_emitter::default_max_listeners;
    } else {
        return *(that->_max_listeners);
    }
}

template<typename Handler_type>
void emit_none(Handler_type& handler, bool is_function, Event_emitter* self)
{
    if (is_function) {
        handler.call(self);
    } else {
        auto len = handler.size();
        std::vector<Handler> listeners{handler.begin(), handler.end()};
        for (auto h : listeners) {
            h.call(self);
        }
    }
}

#endif // BEASTIT_IO_EVENT_EMITTER_H
