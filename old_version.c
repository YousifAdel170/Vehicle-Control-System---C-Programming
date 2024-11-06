#include<stdio.h>
#define WITH_ENGINE_TEMP_CONTROLLER 1 // indicate the engine controller if it on (1) or off (0)
// prototypes
void OptionsVehicleControlSystem();
void VehicleControlSystem(char ch);
void OptionsVehicleEngine();
void VehicleEngineSystem(char ch);
void OptionsTrafficLight();
int RoomTemperature(int data,int *roomTemp);
int TrafficLightData(char input);
int EngineTemperature(int input, int *engineTemp);
void OptionsVehicleEngine();
void vehicleSpeed30(int *speed,int *roomTemp,int *engineTemp);
void DisplayCurrentVechicleState(int *speed, int *roomTemp, int *engineTemp);
void DisplayOptionsScanfVehicleEngine(char ch);
int speed = 0, engineTemp = 90 , roomTemp = 35;  // global variables
int main(void){	// The main
	setbuf(stdout,NULL);
	char ch;
	OptionsVehicleControlSystem();	// display the options of the vehicle control system (main options)
	scanf("%c",&ch);				// choose which option using user (main options)
	VehicleControlSystem(ch);		// process the character into the function (choose which one to perform)
}
void OptionsVehicleControlSystem(){ // display the options of the vehicle control system (main options)
	printf("a. Turn on the vehicle engine");
	printf("\nb. Turn off the vehicle engine");
	printf("\nc. Quit the system");
	printf("\nchoose between these options: ");
}
void VehicleControlSystem(char ch){ // process the character into the function(choose which one to perform)(main process)
	char ch1;		// used when we try again
	switch(ch){
	case 'a':
	case 'A':
		printf("The engine state: ON\n");			// turn the system on
		OptionsVehicleEngine();						// display the options of the engine (minor options)
		scanf(" %c",&ch1);							// choose which option using user (minor option)
		VehicleEngineSystem(ch1);					// process my chosen option (minor process)
		break;
	case 'b':
	case 'B':
		printf("The engine state: OFF\n");			// turn the system off
		OptionsVehicleControlSystem();				// display the options of the vehicle control system (main options)
		scanf(" %c",&ch1);							// choose which option using user (main options)
		VehicleControlSystem(ch1);					// process my chosen option (main process)  (repeat again)
		break;
	case 'c':
	case 'C':
		printf("Quit program");						// since i chose c this means terminate the program
		break;
	default:
		printf("Invalid Option");					// Invalid Option (anything can't be chosen) (not a,b,c)
	}
}
void OptionsVehicleEngine(){						// options of Vehicle Engine (minor options)
	printf("\na. Turn off the engine");
	printf("\nb. Set the traffic light color.");
	printf("\nc. Set the room temperature (Temperature Sensor)");
	printf("\nd. Set the engine temperature (Engine Temperature Sensor)");
	printf("\nchoose between these options: ");
}
void VehicleEngineSystem(char ch){	// process the character into the function(choose which one to perform)(minor process)
	int x;
	switch(ch){									// process the character that pass to the function
	case 'a':
	case 'A':
		printf("The Engine turned OFF\n\n");	// turn of the engine
		OptionsVehicleControlSystem();			// display the options of the vehicle control system (main options)
		scanf(" %c",&ch);						// take from user to chose (main option)
		VehicleControlSystem(ch);				// repeat vehicle control system function Using the chosen character
		break;
	case 'b':
	case 'B':									// traffic light data
		char TrafficFlag;						// initialize character to chose which color (g,o,r)
		OptionsTrafficLight();					// display the options of colors to be chosen(g,o,r)
		scanf(" %c",&TrafficFlag);				// chose the color
		speed = TrafficLightData(TrafficFlag);	// change the speed depends on the color
		if(TrafficFlag == 'o')					// if the color o(orange) this means that the speed 30 km/hr
			vehicleSpeed30(&speed,&roomTemp,&engineTemp);  // Special conditions for 30km/hr speed
		else
			DisplayCurrentVechicleState(&speed,&roomTemp,&engineTemp); // if the color g or r display all the details of the vehicle
		DisplayOptionsScanfVehicleEngine(ch);	// display options & take input from user & process again
		break;
	case 'c':
	case 'C':
		printf("Enter room temperature data: ");
		scanf(" %d",&x);			   // x have the data that you check with it
		RoomTemperature(x,&roomTemp);  //	compare x  with the conditions & put change the room temperature depends on its state
		DisplayCurrentVechicleState(&speed,&roomTemp,&engineTemp);  // display all the details of the vehicle
		DisplayOptionsScanfVehicleEngine(ch);// display options & take input from user & process again
		break;
	case 'd':
	case 'D':
		if(WITH_ENGINE_TEMP_CONTROLLER){
			printf("Enter engine temperature data: ");
			scanf(" %d",&x);			// x have the  data that i compare it with the conditions to get my engine temperature
			EngineTemperature(x,&engineTemp);  // x  have the engine temperature
			DisplayCurrentVechicleState(&speed,&roomTemp,&engineTemp); // display all the details of the vehicle
			DisplayOptionsScanfVehicleEngine(ch); // display options & take input from user & process again
		}
		break;
	default:
		printf("Invalid Option");	// Invalid Option (anything can't be chosen) (not a,b,c,d)
	}
}
void OptionsTrafficLight(){			// The options of colors to be chosen(g,o,r)
	printf("g. Green");
	printf("\no. Orange");
	printf("\nr. Red");
	printf("\nchoose the traffic light to set vehicle speed: ");
}
int RoomTemperature(int data, int *roomTemp){  // take data to be checked & room temperature by address to make it change
	// use to check the data to change the room temperature in specific conditions
	if(data<10){
		*roomTemp = 20;		// value of room temperature = 20 when data less than 10
		printf("Turn AC ON and the temperature is %d\n",*roomTemp);  // Turn the AC ON & temperature = 20
	}
	else if(data>30){
		*roomTemp = 20;		// value of room temperature = 20 when data greater than 30
		printf("Turn AC ON and the temperature is %d\n",*roomTemp); // Turn the AC ON & temperature = 20
	}
	else{
		*roomTemp = 0;					// otherwise , value of room temperature = 20
		printf("Turn the AC OFF\n");    // turn OFF the AC
	}
	return *roomTemp;  					// return the value of the room temperature
}
int TrafficLightData(char input){      // take input to be checked and changing the speed depends on the color
	switch(input){
	case 'G':
	case 'g':
		speed = 100;   // when color is green -> speed = 100  (global value changed)
		break;
	case 'O':
	case 'o':
		speed = 30;		// when color is orange -> speed = 30 (global value changed) (note that this color have specific conditions)
		break;
	case 'r':
	case 'R':
		speed = 0;		// when color is red -> speed = 0 (global value changed)
		break;
	default:
		printf("Invalid Option");		// Invalid Option (anything can't be chosen) (not g,o,r)
	}
	return speed;						// return the value of the speed   (global value)
}
int EngineTemperature(int input,int *engineTemp){	// take input to be checked & engine temperature by address to make it change
	// use to check the input to change the engine temperature in specific conditions
	if(WITH_ENGINE_TEMP_CONTROLLER){ // check if the engine controller is on (1) or off (0)
		if(input<100){
			*engineTemp = 125;		// engine temperature = 125 when the input less than 100
			printf("Engine Temperature Controller ON & temperature is %d\n",*engineTemp);	// Engine Controller ON
		}
		else if(input>150){
			*engineTemp = 125;	// engine temperature = 125 when the input greater than 150
			printf("Engine Temperature Controller ON & temperature is %d\n",*engineTemp);	 // Engine Controller ON
		}
		else{
			*engineTemp = 0;	// otherwise, engine temperature equal zero
			printf("Engine Temperature Controller OFF\n");	// Engine Controller OFF
		}
		return *engineTemp;		// return the value of engine temperature
	}
	return -1;					// return -1 to engine temperature if the engine controller off
}
void vehicleSpeed30(int *speed,int *roomTemp,int *engineTemp){	// change the speed, room temperature, engine temperature (by address)
	if(*speed == 30){						// check if the speed = 30 km/hr
		printf("Since the speed 30  Km/Hr:\n");
		if((*roomTemp != 20))  				// check if the AC not turned on (room temperature not equal 20)
			printf("Turn ON AC\n");			// make it turned on
		else								// The AC was Turned ON
			printf("The AC already ON\n");
		if(WITH_ENGINE_TEMP_CONTROLLER){ // check if the engine controller is on (1) or off (0)
			if((*engineTemp != 125)) // check if the engine controller not turned on (engine temperature not equal 125)
				printf("Turn ON Engine Temperature Controller\n"); // ake it turned on
			else	// The engine controller was Turned ON
				printf("The Engine Temperature Controller already ON\n");
			*engineTemp = (*engineTemp)*(5/4)+1;// change the value of the engine temperature (specific equations) if the speed 30
			printf("The new engine temperature: %d\n",*engineTemp);// print the new value of the engine temperature
		}
		*roomTemp = (*roomTemp)*(5/4)+1;  // change the value of the room temperature (specific equations) if the speed 30
		printf("The new room temperature: %d\n",*roomTemp);	// print the new value of the room temperature
	}
}
void DisplayCurrentVechicleState(int *speed, int *roomTemp, int *engineTemp){ // display all the details of the vehicle at this moment
	if((*speed == -1) && (*roomTemp==-1)&& (*engineTemp==-1))// if these conditions happens means --> state: OFF
		printf("Engine State is OFF\n");
	else{  // otherwise, these conditions
		printf("Engine State is ON\n"); // the engine state is ON
		if((*speed != -1) &&(*speed !=-2)) // check if the speed not initialized
			printf("The Vehicle Speed is %d Km/Hr\n",*speed); // print its value(speed)
		if(*roomTemp==20) // if the room temperature equal 20 turn the AC on & gets its value
			printf("AC: ON and the room temperature is %d\n",*roomTemp);
		else 	// if the room temperature not equal 20 turn the AC OFF & gets its value
			printf("AC: OFF and the room temperature is %d\n",*roomTemp);
		if(WITH_ENGINE_TEMP_CONTROLLER){	// check if the engine controller is on (1) or off (0)
			if(*engineTemp==125) // if the engine temperature equal 125 turn the engine Controller on & gets its value
				printf("Engine Temperature Controller State: ON and the engine temperature is %d C\n",*engineTemp);
			else	 // if the engine temperature not equal 125 turn the engine Controller OFF & gets its value
				printf("Engine Temperature Controller State: OFF and the engine temperature is %d C\n",*engineTemp);
		}
	}
}
void DisplayOptionsScanfVehicleEngine(char ch){ // use this to make all these 3 functions once (since i use it more than one time)
	OptionsVehicleEngine();// display options of the vehicle engines (minor options) again
	scanf(" %c",&ch);// take from user to chose (minor option)
	VehicleEngineSystem(ch);//process the character that pass to the function (minor)
}
