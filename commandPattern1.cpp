// command pattern continued 
class Command
{
	public:
	virtual -Command () {}
virtual void execute(GameActor & actor) = 0; 
}

//GameActor is our "game objecct: class that represents a character in teh game world.
// We pass it in to execute() so that the derived command cna invoke methods on an actor of our choice, like so:

class JumpCommand : public Command 
{
	public:
	virtual void execute (GameActor & actor)
	{
		actor.jump();
	}
};

// now we can use this one class to make any character in the game hop around.
// we're a just missing a piece between the input handler and the command that takes the commmand and invokes it on the right object.
// We change handleInput() so that it reutrns commands:

Command* InputHandler :: handleInput()
{
	if (isPressed(BUTTON_X)) return buttonX_;
	else if( isPressed(BUTTON_Y)) return buttonY_;
	else if (isPressed(BUTTON_A)) return buttonA_;
	else if (isPressed(BUTTON_B)) return buttonB_;
	return NULL;
}

// it can't execute the command immediately since it doesn't know what acto to pass in. here's where we take advantage of teh fact that the ocmmand is a reified call
// we can delay when the call is executed.
// then we need some code that takes teh command and runs it on the actor representing the player.
// e.g.
Command* command = inputHandler.handleInput();
if (command)
{ command-> execute(actor);
}

// assuming actor is a reference to the player's character, this correctly drives him based on the user's input, so we're back to the same behavior we had in the first example. But adding a layer of indirection between the command and the actor tha performs it
// has given us a neat little ability: we can let the player control any actor in teh game now by changing the cator we execute the commands on.
// in practice, that's not a common feature, but thereis a similar use case that does pop up frequently. So far. we've only considered the player driven character.
// but what about all of the other actors in the world? Those are driven by the game's SI. We can use this same command pattern as the interface between the AI engine and the actors; the AI code simply emits Command objects.
// the decoupling here between the AI that selects commands and teh actor code that performs them gives us a lot flexibility. We cna use different AI modules for different actors. Or we can mix and match AI for different kinds of behaviour. Want a more aggressive oppo