//command pattern
// it's a method call wrapped in an object
// Commands are an object-oriented repalcement for callabacks

//without using command pattern
void InputHandler::handleInput()
{
	if (isPressed(Button_X)) jump();
	else if (isPressed(Button_Y)) fireGun();
	else if (isPressd(Button_A)) swapWeapon();
else if (isPressed(Button_B)) lurchIneffectively();
}

// the function above only works if you are willing to hard wire user inputs to game actions,
// but many games let the user configure how their buttons are mapped

// to support that, we need to turn those direct calls to jump() and fireGun() into something that we cna swap out.
// hence an object taht we can use to represent a game action.

//Command pattern
class Command
{
	public:
		virtual -Command() {}
		virtual void execute() = 0;
};

//whenever you have an interface with a single method that doesn't return anything. there's a good chance it's the Command Pattern.

//Then we create subclasses for each of the different game actions:
class JumpCommand : public Command
{
	public:
virtual void execute() {jump():}
};
class FireCommand : public Command {
	public:
	virtual void execute() { fireGun();}
};

class LurchCommand : public Command {
	public:
	virtual void execute() { lurchIneffectively();}
};

class SwapWeaponCommand : public Command {
	public: 
	virtual void execute() { swapweapon();}
};

class InputHandler {
	public: 
	void handleInput();
	private: 
	Command* buttonX_;
	Command* buttonY_;
	Command* buttonA_;
	Command* buttonB_;
};

void InputHandler::handleInpute()
{
	if (isPressed(BUTTON_X)) buttonX_ -> execute();
	else if( isPressed(BUTTON_Y)) buttonY_ -> execute();
	else if (isPressed(BUTTON_A)) buttonA_ -> execute();
	else if (isPressed(BUTTON_B)) buttonB_ -> execute();
}

// this assumes each button will have some command wired up to it.
// if we want ot support buttons that do nothing without having to explicitly check for Null, we can define
// a commadn class whose execute() mehtod does nothing. Then, instead of stting a button handler to NULL, we poitn it to that object.
// this is a pattern called Null object
// Directions for Actors
// The command classes we just defined work for the previous example, but they're pretty limited. The problem is that they assume there are these top level jump(), fireGun(), etc. functions that implicitly know how to find the player's avatar and make him dance like the puppet he is.
// Instead of calling functions that find the commanded object themselves, we'll pass in  the object that we want to order around:
