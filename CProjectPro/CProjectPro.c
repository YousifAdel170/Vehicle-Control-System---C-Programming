/*
	Name: Yousif Adel
	Desctiption: A C-based simulation of a vehicle control system where users can 
				1. turn the engine on/off, 
				2. control vehicle speed based on traffic light colors, 
				3. and manage room and engine temperatures via sensors. 
				The system allows real-time user interaction with menu-driven controls.
 */

#include <stdio.h>

// indicate the engine controller if it on (1) or off (0)
#define WITH_ENGINE_TEMP_CONTROLLER				1

enum Engine
{
	OFF, ON
};

struct vehicleData
{
	int speed;
	int ac_state;
	float room_temperature;
	float engine_temperature;
	int engine_controller_state;
	int engine_state;
};

/* Function Prototypes */

/*
	Fucntion Description:
		responsible for printing the options & take the input from the user then 
		go for the controller function
	Inputs: take the option from the user then process it
*/
void vehicleOptionsAndChoice(struct vehicleData* data);

/*
	Fucntion Description:
		responsible for process the option that took from the user then call each function depending 
		on the option
*/
void vehicleOptionsController(char ch, struct vehicleData* data);

/*
	Fucntion Description:
		responsible for turning the vechicle engine off then go back for main Options 
		to take the new option from the user 
*/
void turnOffEngine(struct vehicleData* data);

/*
	Fucntion Description:
		responsible for turning the vechicle engine ON then take from the user the structure of data to process
		- option 'A' will Turn OFF the Engine
		- option 'B' Will require from the user to enter the traffic color to process it
		- option 'C' Will require from the user to enter the room temperture to process it
		- option 'D' will appear if the engine controller is ON, will require from the 
			to enter engine temperature
		- If the user entered any character else, will Print for the user Invalid Character
*/
void turnOnEngine(char c, struct vehicleData* data);

/*
	Fucntion Description:
		responsible for changing the speed of the Vehicle depending on the traffic color
		- option 'G' will make the speed to 100 to increase the speed
		- option 'O' will make the speed to 30 to lower the speed
		- option 'R' will stop the vehicle
		- If the user entered any character else, will Print for the user Invalid Character
*/
void trafficLightData(struct vehicleData* data, char traffic_color);

/*
	Fucntion Description:
		responsible for changing the room temperature depending on the state of the AC

*/
void roomTemperatureData(struct vehicleData* data);

/*
	Fucntion Description:
		responsible for changing status of the vehicle if the speed is 30
		- if the AC is OFF, turn it ON & set room temperature to 5/4 of its value then increment 
		- the engine controller if it on (1) or off (0) then check its states it OFF, turn it ON then also
			set enigne temperature to 5/4 of its value then increment 

*/
void vehicleSpeedThirtyKM(struct vehicleData* data);

/*
	Fucntion Description:
		responsible for display the current status of the vechile
		- engine state | AC state | vehicle speed | room temperature | engine temperature if ON 

*/
void displayCurrentVehicleState(struct vehicleData* data);

/*
	Fucntion Description:
		responsible for display vehicle options after Enable the Engine
		- choose whether to 
		Turn OFF the Engine | set traffic color | set room temperature | set engine temperature if the controller is ON

*/
void turnOnEngineOptions(struct vehicleData* data);

// indicate the engine controller if it on (1) or off (0)
#if (WITH_ENGINE_TEMP_CONTROLLER)
void engineTemperatureData(struct vehicleData* data);
#endif

int main(void)
{
	setbuf(stdout, NULL);
	struct vehicleData data = {0, OFF, 0, 0, OFF, OFF};
	printf("Welcome To The Vehicle Control System.\n");

	/*
		Fucntion Description:
			responsible for printing the options & take the input from the user then 
			go for the controller function
		Inputs: take the option from the user then process it
	*/
	vehicleOptionsAndChoice(&data);
	char ch;
	scanf(" %c", &ch);

	/*
		Fucntion Description:
			responsible for process the option that took from the user then call each function depending 
			on the option
	*/
	vehicleOptionsController(ch, &data);
	return 0;
}

/*
	Fucntion Description:
		responsible for printing the options & take the input from the user then 
		go for the controller function
	Inputs: take the option from the user then process it
*/
void vehicleOptionsAndChoice(struct vehicleData* data)
{

	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n");
	char ch;
	scanf(" %c", &ch);
	
	/*
		Fucntion Description:
			responsible for process the option that took from the user then call each function depending 
			on the option
	*/
	vehicleOptionsController(ch, data);
}

/*
	Fucntion Description:
		responsible for process the option that took from the user then call each function depending 
		on the option
*/
void vehicleOptionsController(char ch, struct vehicleData* data)
{

	if((ch == 'a') || (ch == 'A')){
		/*
			Fucntion Description:
				responsible for display vehicle options after Enable the Engine
				- choose whether to 
				Turn OFF the Engine | set traffic color | set room temperature | set engine temperature if the controller is ON

		*/
		turnOnEngineOptions(data);
	}
	else if((ch == 'b') || (ch == 'B')){
		/*
			Fucntion Description:
				responsible for turning the vechicle engine off then go back for main Options 
				to take the new option from the user 
		*/
		turnOffEngine(data);
	}

	else if((ch == 'c') || (ch == 'C'))
	{
		printf("Quit the system\n");
		return;
	}
	else
	{
		printf("You have Entered Invalid Character\n");

		/*
			Fucntion Description:
				responsible for printing the options & take the input from the user then 
				go for the controller function
			Inputs: take the option from the user then process it
		*/
		vehicleOptionsAndChoice(data);
	}
}

/*
	Fucntion Description:
		responsible for turning the vechicle engine off then go back for main Options 
		to take the new option from the user 
*/
void turnOffEngine(struct vehicleData* data)
{
	printf("Turn off the vehicle engine\n");

	/*
		Fucntion Description:
			responsible for printing the options & take the input from the user then 
			go for the controller function
		Inputs: take the option from the user then process it
	*/
	vehicleOptionsAndChoice(data);
}


/*
	Fucntion Description:
		responsible for display vehicle options after Enable the Engine
		- choose whether to 
		Turn OFF the Engine | set traffic color | set room temperature | set engine temperature if the controller is ON

*/
void turnOnEngineOptions(struct vehicleData* data)
{
	printf("a. Turn off the engine\n");
	printf("b. Set the traffic light color.\n");
	printf("c. Set the room temperature (Temperature Sensor)\n");
#if (WITH_ENGINE_TEMP_CONTROLLER)
	printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
#endif
	char ch;
	scanf(" %c", &ch);

	/*
		Fucntion Description:
			responsible for turning the vechicle engine ON then take from the user the structure of data to process
			- option 'A' will Turn OFF the Engine
			- option 'B' Will require from the user to enter the traffic color to process it
			- option 'C' Will require from the user to enter the room temperture to process it
			- option 'D' will appear if the engine controller is ON, will require from the 
				to enter engine temperature
			- If the user entered any character else, will Print for the user Invalid Character
	*/	
	turnOnEngine(ch, data);
}

/*
	Fucntion Description:
		responsible for turning the vechicle engine ON then take from the user the structure of data to process
		- option 'A' will Turn OFF the Engine
		- option 'B' Will require from the user to enter the traffic color to process it
		- option 'C' Will require from the user to enter the room temperture to process it
		- option 'D' will appear if the engine controller is ON, will require from the 
			to enter engine temperature
		- If the user entered any character else, will Print for the user Invalid Character
*/
void turnOnEngine(char ch, struct vehicleData* data)
{
	switch(ch)
	{
	case 'a':
	case 'A':
		/*
			Fucntion Description:
				responsible for turning the vechicle engine off then go back for main Options 
				to take the new option from the user 
		*/
		turnOffEngine(data);
		break;
	case 'b':
	case 'B':
		char traffic_color;
		printf("Enter the traffic color: ");
		scanf(" %c",&traffic_color);

		/*
			Fucntion Description:
				responsible for changing the speed of the Vehicle depending on the traffic color
				- option 'G' will make the speed to 100 to increase the speed
				- option 'O' will make the speed to 30 to lower the speed
				- option 'R' will stop the vehicle
				- If the user entered any character else, will Print for the user Invalid Character
		*/
		trafficLightData(data, traffic_color);
		break;
	case 'c':
	case 'C':
		printf("Enter the room temperature: ");
		scanf(" %f", &data->room_temperature);

		/*
			Fucntion Description:
				responsible for changing the room temperature depending on the state of the AC

		*/
		roomTemperatureData(data);
		break;
// indicate the engine controller if it on (1) or off (0)
#if (WITH_ENGINE_TEMP_CONTROLLER)
	case 'd':
	case 'D':
		printf("Enter the engine temperature: ");
		scanf(" %f", &data->engine_temperature);
		engineTemperatureData(data);
		break;
#endif
	default:
		printf("You have Entered Invalid Option\n\n");

		/*
			Fucntion Description:
				responsible for display vehicle options after Enable the Engine
				- choose whether to 
				Turn OFF the Engine | set traffic color | set room temperature | set engine temperature if the controller is ON

		*/
		turnOnEngineOptions(data);
	}
}

/*
	Fucntion Description:
		responsible for changing the speed of the Vehicle depending on the traffic color
		- option 'G' will make the speed to 100 to increase the speed
		- option 'O' will make the speed to 30 to lower the speed
		- option 'R' will stop the vehicle
		- If the user entered any character else, will Print for the user Invalid Character
*/
void trafficLightData(struct vehicleData *data, char traffic_color)
{
	switch(traffic_color)
	{
	case 'G':
	case 'g':
		data->speed = 100;

		/*
			Fucntion Description:
				responsible for display the current status of the vechile
				- engine state | AC state | vehicle speed | room temperature | engine temperature if ON 

		*/
		displayCurrentVehicleState(data);
		break;
	case 'o':
	case 'O':
		data->speed = 30;

		/*
			Fucntion Description:
				responsible for changing status of the vehicle if the speed is 30
				- if the AC is OFF, turn it ON & set room temperature to 5/4 of its value then increment 
				- the engine controller if it on (1) or off (0) then check its states it OFF, turn it ON then also
					set enigne temperature to 5/4 of its value then increment 

		*/
		vehicleSpeedThirtyKM(data);

		/*
			Fucntion Description:
				responsible for display the current status of the vechile
				- engine state | AC state | vehicle speed | room temperature | engine temperature if ON 

		*/
		displayCurrentVehicleState(data);
		break;
	case 'r':
	case 'R':
		data->speed = 0;

		/*
			Fucntion Description:
				responsible for display the current status of the vechile
				- engine state | AC state | vehicle speed | room temperature | engine temperature if ON 

		*/
		displayCurrentVehicleState(data);
		break;
	default:
		printf("You have Entered Invalid Character\n");


		/*
			Fucntion Description:
				responsible for changing the speed of the Vehicle depending on the traffic color
				- option 'G' will make the speed to 100 to increase the speed
				- option 'O' will make the speed to 30 to lower the speed
				- option 'R' will stop the vehicle
				- If the user entered any character else, will Print for the user Invalid Character
		*/
		trafficLightData(data, traffic_color);
		break;
	}
}

/*
	Fucntion Description:
		responsible for changing the room temperature depending on the state of the AC

*/
void roomTemperatureData(struct vehicleData *data)
{
	if( data->room_temperature < 10)
	{
		data->ac_state  = ON;
		data->room_temperature = 20.0;
	}
	else if( data->room_temperature > 30 )
	{
		data->ac_state  = ON;
		data->room_temperature = 20.0;
	}
	else
		data->ac_state = OFF;
	/*
		Fucntion Description:
			responsible for display the current status of the vechile
			- engine state | AC state | vehicle speed | room temperature | engine temperature if ON 

	*/
	displayCurrentVehicleState(data);
}

// indicate the engine controller if it on (1) or off (0)
#if (WITH_ENGINE_TEMP_CONTROLLER)
void engineTemperatureData(struct vehicleData* data)
{
	if( data->engine_temperature < 100)
	{
		data->engine_controller_state = ON;
		data->engine_temperature = 125.0;
	}
	else if( data->engine_temperature > 150 )
	{
		data->engine_controller_state = ON;
		data->engine_temperature = 125.0;
	}
	else
		data->engine_controller_state = OFF;
	/*
		Fucntion Description:
			responsible for display the current status of the vechile
			- engine state | AC state | vehicle speed | room temperature | engine temperature if ON 

	*/
	displayCurrentVehicleState(data);
}
#endif


/*
	Fucntion Description:
		responsible for changing status of the vehicle if the speed is 30
		- if the AC is OFF, turn it ON & set room temperature to 5/4 of its value then increment 
		- the engine controller if it on (1) or off (0) then check its states it OFF, turn it ON then also
			set enigne temperature to 5/4 of its value then increment 

*/
void vehicleSpeedThirtyKM(struct vehicleData* data)
{
	if(data->ac_state == OFF)
	{
		data->ac_state = ON;
		data->room_temperature = data->room_temperature * (5/4) + 1;
	}

// indicate the engine controller if it on (1) or off (0)
#if (WITH_ENGINE_TEMP_CONTROLLER)

	if(data->engine_controller_state == OFF)
	{
		data->engine_controller_state = ON;
		data->engine_temperature = data->engine_temperature * (5/4) + 1;
	}
#endif
}

/*
	Fucntion Description:
		responsible for display the current status of the vechile
		- engine state | AC state | vehicle speed | room temperature | engine temperature if ON 

*/
void displayCurrentVehicleState(struct vehicleData* data)
{
	printf("The Engine State: %d\n", data->engine_state);
	if(data->ac_state == ON)
		printf("AC: ON\n");
	else
		printf("AC: OFF\n");
	printf("Vehicle Speed: %d\n", data->speed);
	printf("Room Temperature: %f\n", data->room_temperature);

#if (WITH_ENGINE_TEMP_CONTROLLER)
	if(data->engine_controller_state == ON)
		printf("Engine Temperature Controller State: ON\n");
	else
		printf("Engine Temperature Controller State: OFF\n");
	printf("Engine Temperature: %f\n", data->engine_temperature);
#endif
	printf("\n");

	/*
		Fucntion Description:
			responsible for display vehicle options after Enable the Engine
			- choose whether to 
			Turn OFF the Engine | set traffic color | set room temperature | set engine temperature if the controller is ON

	*/
	turnOnEngineOptions(data);
}
