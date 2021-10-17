const int BUTTON_PLAY_PAUSE = 8;
const int BUTTON_REWIND = 7;
const int BUTTON_FORWARD = 6;
const int BUTTON_VOLUME_UP = 5;
const int BUTTON_VOLUME_DOWN= 4;
const int BUTTON_NEXT = 3;
const int BUTTON_PREVIOUS = 2;

bool statePlayPause;
bool stateRewind;
bool stateForward;
bool stateVolumeUp;
bool stateVolumeDown;
bool stateNext;
bool statePrevious;

bool previousStatePlayPause;
bool previousStateRewind;
bool previousStateForward;
bool previousStateVolumeUp;
bool previousStateVolumeDown;
bool previousStateNext;
bool previousStatePrevious;

void setup() {
  Serial.begin(9600);
  
  pinMode(BUTTON_PLAY_PAUSE, INPUT_PULLUP);
  pinMode(BUTTON_REWIND, INPUT_PULLUP);
  pinMode(BUTTON_FORWARD, INPUT_PULLUP);
  pinMode(BUTTON_VOLUME_UP, INPUT_PULLUP);
  pinMode(BUTTON_VOLUME_DOWN, INPUT_PULLUP);
  pinMode(BUTTON_NEXT, INPUT_PULLUP);
  pinMode(BUTTON_PREVIOUS, INPUT_PULLUP);

  previousStatePlayPause = !digitalRead(BUTTON_PLAY_PAUSE);
  previousStateRewind = !digitalRead(BUTTON_REWIND);
  previousStateForward = !digitalRead(BUTTON_FORWARD);
  previousStateVolumeUp = !digitalRead(BUTTON_VOLUME_UP);
  previousStateVolumeDown = !digitalRead(BUTTON_VOLUME_DOWN);
  previousStateNext = !digitalRead(BUTTON_NEXT);
  previousStatePrevious = !digitalRead(BUTTON_PREVIOUS);
}

void loop() {
  statePlayPause = !digitalRead(BUTTON_PLAY_PAUSE);
  stateRewind = !digitalRead(BUTTON_REWIND);
  stateForward = !digitalRead(BUTTON_FORWARD);
  stateVolumeUp = !digitalRead(BUTTON_VOLUME_UP);
  stateVolumeDown = !digitalRead(BUTTON_VOLUME_DOWN);
  stateNext = !digitalRead(BUTTON_NEXT);
  statePrevious = !digitalRead(BUTTON_PREVIOUS);
  
  if (statePlayPause != previousStatePlayPause) {
    if (statePlayPause) {
      Serial.println("Play/Pause");
    }
  }
  if (stateRewind != previousStateRewind) {
    if (stateRewind) {
      Serial.println("Rewind");
    }
  }
  if (stateForward != previousStateForward) {
    if (stateForward) {
      Serial.println("Forward");
    }
  }
  if (stateVolumeUp != previousStateVolumeUp) {
    if (stateVolumeUp) {
      Serial.println("Volume_UP");
    }
  }
  if (stateVolumeDown != previousStateVolumeDown) {
    if (stateVolumeDown) {
      Serial.println("Volume_DOWN");
    }
  }
  if (stateNext != previousStateNext) {
    if (stateNext) {
      Serial.println("Next");
    }
  }
   if (statePrevious != previousStatePrevious) {
    if (statePrevious) {
      Serial.println("Previous");
    }
  }
  
  previousStatePlayPause = statePlayPause;
  previousStateRewind = stateRewind;
  previousStateForward = stateForward;
  previousStateVolumeUp = stateVolumeUp;
  previousStateVolumeDown = stateVolumeDown;
  previousStateNext = stateNext;
  previousStatePrevious = statePrevious;
  
  delay(50); //debounce
}
