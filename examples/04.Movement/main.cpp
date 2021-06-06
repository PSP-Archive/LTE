/*
This Tutorial shows how to move and animate SceneNodes. The
basic concept of SceneNodeAnimators is shown as well as manual
movement of nodes using the keyboard.

As always, I include the header files and use the engine namespace.
*/
#include <stdio.h>
#include <wchar.h>
#include <engine.h>
#include "../common.h"

using namespace engine;


/*
In this tutorial, one of our goals is to move a scene node using some
keys on the keyboard. We store a pointer to the scene node we want to
move with the keys here.
The other pointer is a pointer to the engine device, which we need
int the EventReceiver to manipulate the scene node and to get the 
active camera.
*/

scene::ISceneNode* node = 0;
engineDevice* device = 0;


/*
To get events like mouse and keyboard input, or GUI events like 
"the OK button has been clicked", we need an object wich is derived from the 
IEventReceiver object. There is only one method to override: OnEvent. 
This method will be called by the engine when an event happened. 
We will use this input to move the scene node with the keys W and S.
*/
class MyEventReceiver : public IEventReceiver
{
public:
	virtual bool OnEvent(SEvent event)
	{
		/*
		If the button CIRCLE or SQUARE was left up, we get the position of the scene node,
		and modify the Y coordinate a little bit. So if you press CIRCLE, the node
		moves up, and if you press SQUARE it moves down.
		*/

		if (node != 0 && event.EventType == engine::EET_KEY_INPUT_EVENT&&
			!event.KeyInput.PressedDown)
		{
			switch(event.KeyInput.Key)
			{
			case KEY_CIRCLE:
			case KEY_SQUARE:
				{
					core::vector3df v = node->getPosition();
					v.Y += event.KeyInput.Key == KEY_CIRCLE ? 2.0f : -2.0f;
					node->setPosition(v);
				}
				return true;
			}
		}

		return false;
	}
};


/*
The event receiver for moving a scene node is ready. So lets just create
an engine device and the scene node we want to move. We also create some
other additional scene nodes, to show that there are also some different 
possibilities to move and animate scene nodes.
*/
int engineMain(unsigned int argc, void * argv )
{
  // setup psp callbacks
  setupPSP();

  // Create a new used-defined event receiver
	MyEventReceiver receiver;
 
  // Create a new device using the event receiver we created before
	device = createDevice(&receiver);

	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr = device->getSceneManager();


	/*
	Create the node for moving it with the 'W' and 'S' key. We create a
	'test node', which is a cube built in into the engine for testing 
	purposes. We place the node a (0,0,30) and we	assign a texture to it
	to let it look a little bit more interesting.
	*/
	node = smgr->addTestSceneNode();
	node->setPosition(core::vector3df(0,0,30));
	node->setMaterialTexture(0, driver->getTexture("ms0:/media/wall.bmp"));


	/* 
	Now we create another node, moving using a scene node animator. Scene node
	animators modify scene nodes and can be attached to any scene node like
	mesh scene nodes, billboards, lights and even camera scene nodes. Scene node
	animators are not only able to modify the position of a scene node, they can
	also animate the textures of an object for example.
	We create a test scene node again an attach a 'fly circle' scene node to it, letting
	this node fly around our first test scene node.
	*/
	scene::ISceneNode* n = smgr->addTestSceneNode();
	n->setMaterialTexture(0, driver->getTexture("ms0:/media/t351sml.jpg"));

	scene::ISceneNodeAnimator* anim = smgr->createFlyCircleAnimator(
		core::vector3df(0,0,30), 20.0f);
	n->addAnimator(anim);
	anim->drop();


	/*
	The last scene node we add to show possibilities of scene node animators is 
	a md2 model, which uses a 'fly straight' animator to run between to points.
	*/
	scene::IAnimatedMeshSceneNode* anms = smgr->addAnimatedMeshSceneNode(
		smgr->getMesh("ms0:/media/sydney.md2"));

	if (n)
	{
		anim = smgr->createFlyStraightAnimator(core::vector3df(100,0,60), 
			core::vector3df(-100,0,60), 2500, true);
		anms->addAnimator(anim);
		anim->drop();

		/*
		To make to model look better, we disable lighting (we have created no lights,
		and so the model would be black), set the frames between which the animation
		should loop, rotate the model around 180 degrees, and adjust the animation speed
		and the texture.
		To set the right animation (frames and speed), we would also be able to just
		call "anms->setMD2Animation(scene::EMAT_RUN)" for the 'run' animation 
		instead of "setFrameLoop" and "setAnimationSpeed",
		but this only works with MD2 animations, and so you know how to start other animations.
		*/
		anms->setMaterialFlag(video::EMF_LIGHTING, false);

		//anms->setMD2Animation(scene::EMAT_RUN);
		anms->setFrameLoop(320, 367);
		anms->setAnimationSpeed(80);

		anms->setRotation(core::vector3df(0,180.0f,0));
		anms->setMaterialTexture(0, driver->getTexture("ms0:/media/sydney.bmp"));
	}


	/*
	To be able to look at and move around in this scene, 
	we create a first person shooter style camera and make the 
	mouse cursor invisible.
 
  Note: When you show the cursor, CROSS, START and RTRIGGER
        are not sent to the event receiver. CROSS button
        is used as mouse lbutton, rtrigger to increase mouse speed and
        start is used when you click on a textbox to enter in keyboard mode.
	*/
	smgr->addCameraSceneNodeFPS(0, 100.0f, 100.0f);
	device->getCursorControl()->setVisible(false);


	/*
	We have done everything, so lets draw it. We also write the current
	frames per second and the name of the driver to the caption of the
	window.
	*/
	while(device->run())
	{
		driver->beginScene(true, true, video::SColor(255,113,113,133));

		smgr->drawAll(); // draw the 3d scene

		driver->endScene();

	}
  sceKernelExitGame();
	
	return 0;
}

