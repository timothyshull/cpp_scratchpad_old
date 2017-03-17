import QtAudioEngine 1.0
import QtQuick 2.0

AudioEngine {

    AudioCategory {
        name:"sfx"
        volume: 1
    }

    AudioCategory {
        name:"music"
        volume: 1
    }

    AttenuationModelInverse {
       name:"default"
       start: 20
       end: 1000
       rolloff: 1
    }

    AttenuationModelLinear {
       name:"shipengine"
       start: 20
       end: 180
    }

    AudioSample {
        name:"engine"
        source: "engine-loop.wav"
        preloaded:true
    }

    AudioSample {
        name:"horn"
        source: "horn.wav"
    }
    AudioSample {
        name:"whistle"
        source: "whistle.wav"
    }
    Sound {
        name:"shipengine"
        attenuationModel:"shipengine"
        category:"sfx"
        PlayVariation {
            looping:true
            sample:"engine"
            maxGain:0.9
            minGain:0.8
        }
    }

    Sound {
        name:"effects"
        category:"sfx"
        PlayVariation {
            sample:"horn"
            maxGain:2.0
            minGain:0.9
        }
        PlayVariation {
            sample:"whistle"
            maxGain:1.0
            minGain:0.8
        }
    }

    dopplerFactor: 1
    speedOfSound: 343.33

    listener.up:"0,0,1"
    listener.position:"0,0,0"
    listener.velocity:"0,0,0"
    listener.direction:"0,1,0"
}