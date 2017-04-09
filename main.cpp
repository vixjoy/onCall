#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>

#include <string.h>

using namespace std;

enum catagory{
    HEIMLICH, INFANT, CPR, SUICIDE, INTRUDER, ALONE, OTHER
};
struct word{

    
    string data;
    catagory cat;
    bool inUse;
    
    word(){
        inUse = false;
        data = "";
        cat = OTHER;
    }
};

int main(){
    int Hc=0,Bc=0,Cc=0,Sc=0,Ic=0,Ac=0;
    int i=0,j=0;
    word a[100] = {*new word()};
    ifstream in;
    ofstream out;
    string line;
    in.open ("/Users/Victoria/Desktop/input.txt");
    out.open("/Users/Victoria/Desktop/output.txt");
    
    
    
    if(in&&out){
        getline(in, line);
        //cout<<line<<endl;
        
        
        a[0].inUse = true;
        while(i<line.size()){
            if(line[i]==' '){
                j++;
                i++;
                a[j].inUse = true;
            }
            else if(line[i] != '\0'){
                line[i] = tolower(line[i]);
                a[j].data = a[j].data + line[i];
                i++;
            }
        }
        j=0;
        cout<<"|";
        while(a[j].inUse){
            cout<<a[j++].data<<"|";
        }
        cout<<endl;
        j=0;
        while(a[j].inUse){
            if(a[j].data == "choke" ||
               a[j].data == "choking" ||
               a[j].data == "breathing" ||
               a[j].data == "breathe" ||
               a[j].data == "heimlich"){
                
                a[j].cat = HEIMLICH;
                
            }
            else if(a[j].data == "baby" ||
                    a[j].data == "babies" ||
                    a[j].data == "infant"){
                cout<<"baby"<<endl;
                a[j].cat = INFANT;
                
            }
            
            else if(a[j].data == "cpr" ||
                    a[j].data == "heart"){
                cout<<"CPR"<<endl;
                a[j].cat = CPR;
                
            }
            else if(a[j].data == "kill" ||
                    a[j].data == "killing" ||
                    a[j].data == "suicide" ||
                    a[j].data == "depression" ||
                    a[j].data == "depressed"){
                a[j].cat = SUICIDE;
                cout<<"suicide active"<<endl;
                
            }
            else if(a[j].data == "house" ||
                    a[j].data == "stranger" ||
                    a[j].data == "break" ||
                    a[j].data == "intruder"||
                    a[j].data == "flames"||
                    a[j].data == "flame"||
                    a[j].data == "burn"||
                    a[j].data == "fire"){
                
                a[j].cat = INTRUDER;
                
            }
            else if(a[j].data == "alone" ||
                    a[j].data == "by" ||
                    a[j].data == "bye"){
                
                a[j].cat = ALONE;
                
            }
            else{
                a[j].cat = OTHER;
            }
            j++;
        }
        
        j=0;
        while(a[j].inUse){
            if(a[j].cat == HEIMLICH){
                cout<<Hc<<endl;
                Hc++;
            }
            else if(a[j].cat == INFANT){
                Bc++;//baby counter
            }
            else if(a[j].cat == CPR){
                Cc++;
            }
            else if(a[j].cat == SUICIDE){
                Sc++;
                cout<<"test1"<<endl;
            }
            else if(a[j].cat == INTRUDER){
                Ic++;
            }
            else if(a[j].cat == ALONE){
                Ac++;
            }
            else{
                //other;
            }
            j++;
        }
     //heimlic commands
        if(Hc>0&&Bc==0&&Ac==0){
            //normal heimlic
            out<<"do not perform abdominal thrusts on infants less than 1 year old. If the person is sitting or standing, position yourself behind the person and reach your arms around his or her waist. For a child, you may have to kneel. Place your fist, thumb side in, just above the person's belly button. Grasp the fist tightly with your other hand. Make quick, upward and inward thrusts with your fist. If the person is lying on his or her back, straddle the person facing the head. Push your grasped fist upward and inward in a movement similar to the one above."<<endl;
        }
        else if(Hc>0&&Bc>0){
            //perform heimlic on a baby
           out<<"The first thing to do when you see a baby struggling to breathe is check whether she can cough or make sounds. If she can cough firmly, then let her cough to try and dislodge the object that is obstructing her breathing. If you are worried about her breathing and she cannot dislodge the object through coughing you should call for emergency medical help. If your baby can cough forcefully or cry strongly do not attempt the following steps to dislodge it. Look to see if the baby is turning blue, losing consciousness, or is waving his arms desperately without making any sound. If you can see the obstruction in the baby's mouth or throat and it is easily accessible you can remove it, but do not feel around in the baby's throat. If the baby is unconscious, remove any visible objects from the mouth and begin CPR until the ambulance arrives. you need to act quickly to dislodge the object which is obstructing his airway. The first technique to use is back blows. Turn the baby face down on your lap for the back blows. Hold the baby in this secure face-down position and be sure to support the baby's head. The front of the baby is supposed to be firmly leaning against your arm, and you can use your thigh for support. Ensure that you are not covering the baby's mouth or twisting his neck. The baby's head should be slightly lower than her chest. administer five firm but gentle back blows. Slap the baby's back, between her shoulder blades, with the heel of your hand five times. After five slaps, stop and check the baby's mouth to see if the blockage has become dislodged. If there is an obvious blockage which you can see and reach, carefully take it out. Do not do this if you risk pushing it further in. If, after administering five back blows, the baby's airway has not been cleared, you will need to perform five chest thrusts. In this case, it's time to perform chest thrusts. Place the baby facing upwards across your lap, with the head lower than the body. Use your thigh or lap for support and be sure to support the head.Place two fingers on the centre of his breastbone, just below the nipples, or about one finger's breadth below the nipples. Then give five quick thrusts down.[11] The force you exert should compress the chest between a third and a half of its depth. Check if the blockage has been dislodged and if it is easy for you to take it out do so, but again, do not risk pushing it in further. Continue to perform back blows and chest thrusts in this cycle until the blockage has been removed or until help arrives. Even after the object has been dislodged you should pay close attention to your baby. It is possible that some of the substance which caused the blockage may remain and cause problems in the near future. If she has any trouble swallowing, or has a persistent cough, you should seek medical help immediately. Take your child to see your doctor or to your local Hospital, or Emergency Room."<<endl;
            cout<<"Baby CPR"<<endl;
        }
        else if(Hc>0&&Ac>0){
            out<<"Make a fist with one hand. Place your thumb of this hand below your rib cage and above your navel. Grasp your fist with your other hand. Press your fist into the area with a quick upward movement."<<endl;
            //perfom heimlic on self
        }
    //CPR commands
        else if(Cc>0&&Bc==0&&Ac==0){
            out<<"Kneel beside the person who needs help. Place the heel of one hand on the center of the chest. Place the heel of the other hand on top of the first hand, then lace your fingers together. Position your body so that your shoulders are directly over your hands, and keep your arms straight. Push hard, push fast. Use your body weight to help you administer compressions that are at least 2 inches deep and delivered at a rate of at least 100 compressions per minute. (Just be sure to let chest rise completely between compressions.) Keep pushing. Continue hands-only CPR until you see obvious signs of life, like breathing, another trained responder or EMS professional can take over, you're too exhausted to continue, an AED becomes available, or the scene becomes unsafe. "<<endl;
        }
        else if(Cc>0&&Bc>0){
            out<<"Check if the baby is conscious. It's best to flick your fingers against the feet. If the baby doesn't respond, ask someone to call for emergency help while you go on to the next step. If you are alone with the baby, follow the steps below for 2 minutes (to provide immediate first aid) before calling emergency services. If the baby is conscious but choking, administer first aid before attempting CPR. Whether the baby is breathing should determine your course of action.If the baby is coughing or gagging while choking, let her continue to cough and gag on her own. Coughing and gagging — a good sign — means that her airways are only partially blocked. Check for breathing again, and this time place your index and middle fingers on the inside of the baby's arm, between the elbow and the shoulder. If there is no pulse and no breathing, continue with the next steps to perform CPR, which is a combination of compressions and breaths.Gently lift the baby's head back and chin up to open the child's airway. The airway is small, so this won't be a drastic movement. Again, check for breathing during this time, but for no longer than 10 seconds.If you have one, put a face shield on the baby to prevent the exchange of bodily fluids. Pinch the nose shut, tilt the head back, push up the chin, and give two breaths, each lasting about one second. Exhale gently until the chest rises; exhaling too forcefully can cause injury.Remember to pause in between breaths to let the air out. If you feel that the breaths did not go in (the chest doesn't rise at all) the airway is obstructed and the child may be choking. Terminate this program and ask for baby heimlich. If there is no pulse, begin CPR on baby.Take two or three fingers held together and place them in the middle of the baby's chest right below the nipples. Gently, fluidly compress the baby's chest 30 times. If you need to brace your fingers because they are getting tired, use your second hand to help assist the process. Otherwise, keep your second hand cradling the baby's head. Try to perform your chest compressions at a rate of about 100 compressions per minute.[4] That may seem like a lot, but it's actually only a little over one chest compression a second. Still, try to maintain a fluid push and release when performing compressions.Press down 1/3 to 1/2 the depth of the baby's chest. This usually works out to about 1 and 1/2 inches.  At the right speed, you should do about 5 sets of rescue breaths and compressions within approximately two minutes. Once you start CPR, don't stop unless You see signs of life (baby moves, coughs, breathes noticeably, or vocalizes). Vomiting is not a sign of life."<<endl;
            //perform CPR on a baby
        }
    //Suicide prevention
        else if(Sc>0){
            cout<<"test3"<<endl;
            out<<"The National Suicide Prevention Lifeline is a national network of local crisis centers that provides free and confidential emotional support to people in suicidal crisis or emotional distress 24 hours a day, 7 days a week. We're committed to improving crisis services and advancing suicide prevention by empowering individuals, advancing professional best practices, and building awareness."<<endl;
            //provide suicide hotline phone number
        }
    //Intruder or Fire
        else if(Ic>0){
             out<<"Find saftey. Call 911."<<endl;
            //leave the house call 911
        }
        else{
            out<<"I'm sorry. I don't know how I can help. Try again with any of the following key words: fire, Heimlich, sea pea are, suicide, infant and many more"<<endl;
        }
    }
    
    else{
        out<<"error"<<endl;
    }
    
    out.close();
    in.close();
    cout<<"end"<<endl;
    return 0;
}
