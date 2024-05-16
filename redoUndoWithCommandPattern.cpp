//UNDO AND REDO USING COMMAND PATTERN
class Command
{
public:
virtual ~Command() {}
virtual void execute() = 0;
virtual void undo() = 0;
}

class MoveUnitCommand : public Command {
	public: 
	MoveUnitCommand(Unit* unit, int x, inty ): unit_(unit), xBefore_(0),
	yBefore_(0), x_(x), y_(y)
	{}
		
	virtual void execute()
		{ 
		xBefore_ = unit_->x();
		yBefore_ = unit_->y();
		unit_-> moveTo(x_, y_);
		}
		
	virtual void undo()
	{
	unit_->moveTo(xBefore_, yBefore_);
	}

	private: 
	 Unit* unit_;
	 int xBefore_, yBefore_;
	 int x_, y_;
};

// this is a little differnt from our previous commmands. In the last example we wanted to abstract the commadn from the cator that it modified. In this case, we specifically want ot bind it to the unit_
// being moved. An instance of this command isn't a general "move something" operation that you could use in a bunch of contexts; it's a specific concrete move in teh game's sequence of turns.

Command* handleInput()
{
Unit* unit = getSelectedUnit();
if (isPressed(BUTTON_UP)) {
// Move the unit up one.
int destY = unit->y() - 1;
return new MoveUnitCommand(unit, unit->x(), destY);
}
if (isPressed(BUTTON_DOWN)) {
// Move the unit down one.
int destY = unit->y() + 1;
return new MoveUnitCommand(unit, unit->x(), destY);
}
// Other moves...
return NULL;
}




