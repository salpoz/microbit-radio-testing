#include "MicroBit.h"
//#include <math.h>

MicroBit uBit;

//////////////////////////////////////
/////       RECEIVER UNIT       //////
//////////////////////////////////////
/*ManagedString recvData;

void onRecv(MicroBitEvent){
    recvData = uBit.radio.datagram.recv();
    if(recvData == "1"){
        uBit.serial.printf("1\r\n");
    }
}


int main(){
    uBit.init();
    uBit.radio.enable();
    uBit.radio.setGroup(1);

    uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, onRecv);

    release_fiber();
}*/




/*
//////////////////////////////////////
/////       SENDER UNIT       //////
//////////////////////////////////////
int x;
int y;
int z;

int main(){
    uBit.init();
    uBit.radio.enable();
    uBit.radio.setGroup(1);

    uBit.display.scroll("READY", 60);
    while(1){
        x = uBit.accelerometer.getX();
        y = uBit.accelerometer.getY();
        z = uBit.accelerometer.getZ();
        if((x > 2000 || x < -2000) || (y > 2000 || y < -2000) || (z > 2000 || z < -2000)){
            uBit.radio.datagram.send("1");
            uBit.sleep(500);
        }
    }

    release_fiber();
}
*/

/*
//////////////////////////////////////
/////  SENDER UNIT version 2.0  //////
//////////////////////////////////////

void onPressed(MicroBitEvent e){
    if(e.source == MICROBIT_ID_BUTTON_A){
        uBit.radio.datagram.send("THROW");
    }

    if(e.source == MICROBIT_ID_BUTTON_B){
        uBit.radio.datagram.send("SHAKE");
    }
}



int main(){
    uBit.init();
    uBit.accelerometer.setRange(3);
    uBit.radio.enable();
    uBit.radio.setGroup(1);

    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A,MICROBIT_BUTTON_EVT_DOWN, onPressed);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_B,MICROBIT_BUTTON_EVT_DOWN, onPressed);
    
    *
    bool sent = false;
    int gesture;
    int x;
    int y;
    int z;
    int previous_gesture = -1;

    
    while(true){
        
        uBit.accelerometer.updateSample();
        gesture = uBit.accelerometer.getGesture();
        
        if(gesture == MICROBIT_ACCELEROMETER_EVT_FREEFALL){
            if(previous_gesture != gesture){
                previous_gesture = gesture;
                uBit.radio.datagram.send("FALL");
            }
        } else {
            gesture = false;
        }

        previous_gesture = -1;

        x = pow(uBit.accelerometer.getX(), 2.0);
        y = pow(uBit.accelerometer.getY(), 2.0);
        z = pow(uBit.accelerometer.getZ(), 2.0);
        
        double f = sqrt(x+ y + z);
        int force = (int)f;
        if(force > 6000){
            //uBit.serial.printf("THROW\r\n");
            if(!sent){
                uBit.radio.datagram.send("THROW");
                sent = true;
            }            
        }

        uBit.sleep(20);
    }*

    release_fiber();
}
*/


////////////////////////////////////////////
/////   RECEIVER UNIT  version 2.0    //////
////////////////////////////////////////////
ManagedString recvData;

void onRecv(MicroBitEvent){
    recvData = uBit.radio.datagram.recv();
    if(recvData == "THROW"){
        uBit.serial.printf("throw\r\n");
    }
    if(recvData == "SHAKE"){
        uBit.serial.printf("shake\r\n");
    }
}


int main(){
    uBit.init();
    uBit.radio.enable();
    uBit.radio.setGroup(1);

    uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, onRecv);

    release_fiber();
}
