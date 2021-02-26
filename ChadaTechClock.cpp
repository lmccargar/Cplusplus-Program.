// ChadaTechClock.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
 * CS 210 course "audition" Chada Tech Clock.
 * @Auditionee: Lynn McCargar
 * @Version: 1.12
 * @Date: 01/23/2021
 */
#include <iostream> //Handles input/output
#include <ctime> //Handles time.

using namespace std; //Handles class, object, and function in the code.

//Class used to track time.

class time {

public:
	virtual ~time() = default;

	int hour{};

	int minute{};

	int second{};

	virtual void addOneHour() = 0;

	virtual void addOneMinute() = 0;

	virtual void addOneSecond() = 0;

};

//_12_Hour_Time class which inherits the time class.

class _12_Hour_Time final : public time {

	//Method to manage the 12 hour time.

public:

	_12_Hour_Time(int h, int m, int s) {

		hour = h;

		minute = m;

		second = s;

	}

	//Method to add one hour to the clock.

	void addOneHour() override {

		if (hour == 11) {

			hour = 0;

		}
		else {

			hour += 1;

		}

	}

	//Method to add one minute to the clock.

	void addOneMinute() override {

		if (minute == 59) {

			minute = 0;

			addOneHour();

		}
		else {

			minute += 1;

		}

	}

	//Method to add one second to the clock.

	void addOneSecond() override {

		if (second == 59) {

			second = 0;

			addOneMinute();

		}
		else {

			second += 1;

		}

	}
};

//_24_Hour_Time class which inherits the time class.

class _24_Hour_Time final : public time {

	//Method to manage 24 hour time.

public:

	_24_Hour_Time(int h, int m, int s) {

		hour = h;

		minute = m;

		second = s;

	}

	//Method to add one hour to the clock.

	void addOneHour() override {

		if (hour == 23) {

			hour = 0;

		}
		else {

			hour += 1;

		}

	}

	//Method to add one minute to the clock.

	void addOneMinute() override {

		if (minute == 59) {

			minute = 0;

			addOneHour();

		}
		else {

			minute += 1;

		}

	}

	//Method to add one second to the clock.

	void addOneSecond() override {

		if (second == 59) {

			second = 0;

			addOneMinute();

		}
		else {

			second += 1;

		}

	}
};


		//Displaytime will be able to display time with appropriate formatting.

		void displayTime(const _12_Hour_Time& time12, const _24_Hour_Time& time24) {

			cout << "*************************** ***************************" << endl;

			cout << "*     12-Hour Clock       * *      24-Hour Clock      *" << endl;

			cout << "*     "; if (time12.hour < 10) cout << "0"; cout << time12.hour << ":";

			if (time12.minute < 10) cout << "0"; cout << time12.minute << ":";

			if (time12.second < 10) cout << "0"; cout << time12.second;

			if (time12.hour == 0 && time12.hour == 12) cout << " AM"; else cout << " PM";

			cout << "         * *         ";

			if (time24.hour < 10) cout << "0"; cout << time24.hour << ":";

			if (time24.minute < 10) cout << "0"; cout << time24.minute << ":";

			if (time24.second < 10) cout << "0"; cout << time24.second;

			cout << "        *" << endl;

			cout << "*************************** ***************************" << endl;

		}

		//Create the options menu interface.

		static int displayMenu() {

			cout << "               " << "***************************" << endl;

			cout << "               " << "* 1 - Add One Hour        *" << endl;

			cout << "               " << "* 2 - Add One Minute      *" << endl;

			cout << "               " << "* 3 - Add One Second      *" << endl;

			cout << "               " << "* 4 - Exit Program        *" << endl;

			cout << "               " << "***************************" << endl;

			cout << "          " << "Please choose an option from the menu." << endl;

			return 0;
		}

		//Declare main method.

int main()
{

			//Pulls time and create clocks.
			time_t timeNow;
			timeNow = time(nullptr);
			tm time12{};
			localtime_s(&time12, &timeNow);
			tm time24{};
			localtime_s(&time24, &timeNow);
			time(&timeNow);

			_12_Hour_Time time_12_Clock(time12.tm_hour - 12, time12.tm_min, time12.tm_sec);

			_24_Hour_Time time_24_Clock(time24.tm_hour, time24.tm_min, time24.tm_sec);

			displayTime(time_12_Clock, time_24_Clock);

			while (true) {

				displayMenu();

				int choice;

				cin >> choice;

				//Add interface functionality.

				switch (choice) {

				case 1:


					time_12_Clock.addOneHour();

					time_24_Clock.addOneHour();

					displayTime(time_12_Clock, time_24_Clock);

					break;

				case 2:

					time_12_Clock.addOneMinute();

					time_24_Clock.addOneMinute();

					displayTime(time_12_Clock, time_24_Clock);

					break;

				case 3:

					time_12_Clock.addOneSecond();

					time_24_Clock.addOneSecond();

					displayTime(time_12_Clock, time_24_Clock);

					break;

				case 4:

					cout << "Now exiting program.";

					exit(1);


				default:

					//Put an error check in case user add invalid option.

					cout << "Error: Invalid choice. Please try again." << endl;

					break;

				}
			}
		}
