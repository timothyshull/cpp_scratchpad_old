//
// Created by Tim Shull on 10/23/16.
//

#ifndef PCKBK_UTIL_H
#define PCKBK_UTIL_H

#include<string>
#include<vector>
#include<chrono>


namespace util {
    void split(const std::string &s, char delimiter, std::vector<std::string> &elems);

    void replace_all(std::string &s, const std::string to_replace, const std::string &replacement) {
        std::string::size_type n = 0;
        while ((n = s.find(to_replace, n)) != std::string::npos) {
            s.replace(n, to_replace.size(), replacement);
            n += replacement.size();
        }
    }

    // from gsl
    template<class F>
    class final_act {
    public:
        explicit final_act(F f) noexcept : f_(std::move(f)), invoke_(true) {}

        final_act(final_act &&other) noexcept : f_(std::move(other.f_)), invoke_(other.invoke_) {
            other.invoke_ = false;
        }

        final_act(const final_act &) = delete;

        final_act &operator=(const final_act &) = delete;

        ~final_act() noexcept {
            if (invoke_) f_();
        }

    private:
        F f_;
        bool invoke_;
    };

    template<class F>
    inline final_act<F> finally(const F &f) noexcept {
        return final_act<F>(f);
    }

    template<class F>
    inline final_act<F> finally(F &&f) noexcept {
        return final_act<F>(std::forward<F>(f));
    }

    std::streamoff stream_size(std::istream &f);

    bool file_to_string(std::istream &f, std::string &result);

    template<typename T>
    class Basic_stopwatch : T {
        typedef typename T BaseTimer;
    public:
        explicit Basic_stopwatch(bool start);

        explicit Basic_stopwatch(char const *activity = "Stopwatch",
                                 bool start = true);

        Basic_stopwatch(std::ostream &log,
                        char const *activity = "Stopwatch", bool start = true);

        ~Basic_stopwatch();

        unsigned get_lap() const;

        bool is_started() const;

        unsigned show_time(char const *event = "show_time");

        unsigned start(char const *event_name = "start");

        unsigned stop(char const *event_name = "stop");

    private:
        char const *m_activity;
        unsigned m_lap;
        std::ostream &m_log;
    };

    class Timer_base {
    public:
        Timer_base() : m_start(std::chrono::system_clock::time_point::min()) {}

        void clear() {
            m_start = std::chrono::system_clock::time_point::min();
        }

        bool is_started() const {
            return (m_start.time_since_epoch() != std::chrono::system_clock::duration(0));
        }

        void start() {
            m_start = std::chrono::system_clock::now();
        }

        unsigned long get_time_in_ms() {
            if (is_started()) {
                std::chrono::system_clock::duration diff;
                diff = std::chrono::system_clock::now() - m_start;
                return (unsigned) (duration_cast<std::chrono::milliseconds>(diff).count());
            }
            return 0;
        }

    private:
        std::chrono::system_clock::time_point m_start;
    };
};


#endif //PCKBK_UTIL_H
