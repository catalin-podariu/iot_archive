#include <INextionBooleanValued.h>
#include <INextionCallback.h>
#include <INextionColourable.h>
#include <INextionFontStyleable.h>
#include <INextionNumericalValued.h>
#include <INextionStringValued.h>
#include <INextionTouchable.h>
#include <INextionWidget.h>
#include <Nextion.h>
#include <NextionButton.h>
#include <NextionCallbackFunctionHandler.h>
#include <NextionCheckbox.h>
#include <NextionCrop.h>
#include <NextionDualStateButton.h>
#include <NextionGauge.h>
#include <NextionHotspot.h>
#include <NextionNumber.h>
#include <NextionPage.h>
#include <NextionPicture.h>
#include <NextionProgressBar.h>
#include <NextionRadioButton.h>
#include <NextionSlider.h>
#include <NextionSlidingText.h>
#include <NextionText.h>
#include <NextionTimer.h>
#include <NextionTypes.h>
#include <NextionVariableNumeric.h>
#include <NextionVariableString.h>
#include <NextionWaveform.h>

#include <Nextion.h>


Nextion nex(Serial1); //Display Nextion collegato alla Serial1


int R1 = 2, R2 = 3, R3 = 4, R4 = 4, R5 = 5, R6 = 6;
 
NextionPage p0(nex,0,0,"0"); //Pagina
NextionPage p1(nex,1,0,"1");
 
NextionDualStateButton buttonZero = NextionDualStateButton(nex, 12, 13, "buttonLiving");
NextionDualStateButton buttonOne = NextionDualStateButton(nex, 4, 17, "buttonBed");
NextionDualStateButton buttonTwo = NextionDualStateButton(nex, 18, 7, "buttonHall");
NextionDualStateButton buttonThree = NextionDualStateButton(nex, 10, 11, "buttonLeds");
NextionDualStateButton buttonFour = NextionDualStateButton(nex, 2, 3, "buttonBath");
NextionDualStateButton buttonFive = NextionDualStateButton(nex, 8, 9, "buttonKitchen");
NextionDualStateButton buttonSex = NextionDualStateButton(nex, 5, 6, "buttonAll");
 
char buffer[100] = {0};
 
INextionTouchable *buttonList[] = {
    &buttonLiving, &buttonBed, &buttonHall, &buttonLeds, &buttonBath, &buttonKitchen, &buttonAll,
    NULL
};


void setup(void) {    
//    nexInit();
    buttonLiving.attachPop(buttonZeroPopCallback, &buttonLiving);
    buttonBed.attachPop(buttonZeroPopCallback, &buttonBed);
    buttonHall.attachPop(buttonZeroPopCallback, &buttonHall);
    buttonLeds.attachPop(buttonZeroPopCallback, &buttonLeds);
    buttonBath.attachPop(buttonZeroPopCallback, &buttonBath);
    buttonKitchen.attachPop(buttonZeroPopCallback, &buttonKitchen);
    buttonAll.attachPop(buttonZeroPopCallback, &buttonAll);
    
    Serial.println("Setup completed."); 
}
 
void loop()
{   
    nex.poll();
}
 
void buttonZeroPopCallback(void *ptr)
{
    uint32_t dual_state;
    NextionDualStateButton *btn = (NextionDualStateButton *)ptr;
    
    Serial.println("Callback");
    Serial.println("ptr=");
  
    Serial.println((uint32_t)ptr); 
    memset(buffer, 0, sizeof(buffer));
    
    buttonZero.getValue(&dual_state);
    buttonOne.getValue(&dual_state);
    buttonTwo.getValue(&dual_state);
    buttonThree.getValue(&dual_state);
    buttonFour.getValue(&dual_state);
    buttonFive.getValue(&dual_state);
 
//    if(dual_state){digitalWrite(R1, HIGH);}else{digitalWrite(R1, LOW);}
//    if(dual_state){digitalWrite(R2, HIGH);}else{digitalWrite(R2, LOW);}
//    if(dual_state){digitalWrite(R3, HIGH);}else{digitalWrite(R3, LOW);}
//    if(dual_state){digitalWrite(R4, HIGH);}else{digitalWrite(R4, LOW);}
//    if(dual_state){digitalWrite(R5, HIGH);}else{digitalWrite(R5, LOW);}
//    if(dual_state){digitalWrite(R6, HIGH);}else{digitalWrite(R6, LOW);}
}
