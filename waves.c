// running average filter - Mike Cook
// using byte buffers
// Open up the plot window

const int bufferSize = 250;

byte inBuffer[bufferSize], outBuffer[bufferSize];


void setup() {
    Serial.begin(250000);
    displayWave(); // clear display
    makeWave(2);
    delay(600);
    runningAvfilter(20);
    displayWave();
}


void loop() {
}



void makeWave(int wave){
    switch(wave){
        case 0: makeTriangle();
    break;
        case 1: makeSin();
    break;
        case 2: makeSquare();
    break;
        case 3: makeNoise();
    }
}


void measure(){
    int point = bufferSize - 1;
    float accIn = 0.0, accOut = 0.0;
    while(point > 0){
        if(outBuffer[point] > 0) accOut += (float)outBuffer[point];
            else
                accOut -= (float)outBuffer[point];
        if(inBuffer[point] > 0) accIn += (float)inBuffer[point];
            else
            accIn -= (float)inBuffer[point];
        point --;
    }
    att = 10* log(accOut / accIn);
    for(int i=0; i<4; i++) {
    Serial.println(att);
    displayCount--;
    }
}

void highPass(int n){
    for(int i=1; i<(bufferSize); i++){
        outBuffer[i] = 0.3*(float)outBuffer[i-1] +(float)n*0.3*(float)inBuffer[i] -
        0.3*(float)inBuffer[i-1];
    }
}
void bandPass(){
    for(int i=2; i<(bufferSize); i++){
        outBuffer[i] = (0.9*(float)outBuffer[i-1] - 0.8* (float) outBuffer[i-2]
        + (float)inBuffer[i] );
    }
}

void average(int n){
    int acc;
    for(int i=0; i<(bufferSize-n); i++){
        acc=0;
        for(int j=0; j<n; j++){
            acc += inBuffer[i+j];
        }
        outBuffer[i]= acc/n; // save average
    }
}


void notchFilter(){ // for a 20 sample wave
    // prime output buffer
    outBuffer[0] = 0; // inBuffer[0]
    outBuffer[1] = 0; // inBuffer[1]
    for(int i=2; i<(bufferSize); i++){
        outBuffer[i] = ((1.8523*(float)outBuffer[i-1] - 0.94833* (float) outBuffer[i-2]
        + (float)inBuffer[i] - 1.9021*(float) inBuffer[i-1] + (float)inBuffer[i-2]));
    }
}




void makeTriangle(){
    // (increment/bufferSize) determines the number of cycles
    int increment = 8, wave = 0;
    // make a triangle wave
    for(int i=0; i<bufferSize; i++){
        wave += increment;
        if(wave > (255 - increment) || wave < 0) {
        increment = -increment;
        wave += increment;
    }
    inBuffer[i] = (byte)wave;
    }
}


void makeSin(){
// increment controls the frequency
    int count = 0, increment= 10;
    for(int i=0; i<bufferSize; i++){
        count += increment;
    if(count > 360) count -= 360;
        inBuffer[i] = (byte)(127+ (127.0*sin((float)count / 57.2957795 )));
    }
}


void makeSquare(){
    int period = 30, count = 0;
    boolean change = true;
    for(int i=0; i<bufferSize; i++){
        count++;
        if(count >= period){
            count = 0;
            change = !change;
        }
            if(change){
            inBuffer[i] = 255;
        }
    else {
        inBuffer[i] = 0;
        }
    }
}


void makeNoise(){
    randomSeed(analogRead(4));
    for(int i=0; i<bufferSize; i++){
        inBuffer[i] = (byte)random(255);
    }
}

void runningAvfilter(int n){
    int acc;
    for(int i=0; i<(bufferSize-n); i++){
        acc=0;
    for(int j=0; j<n; j++){
        acc += inBuffer[i+j];
    }
    outBuffer[i]= acc/n; // save average
    }
}


void displayWave(){
    for(int i=0; i<bufferSize; i++){
        Serial.println(inBuffer[i]);
    }
    for(int i=0; i<bufferSize; i++){
        Serial.println(outBuffer[i]);
    }
}