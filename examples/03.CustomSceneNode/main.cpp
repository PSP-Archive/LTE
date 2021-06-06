/*
This Tutorial is a tutorial for more advanced developers.
If you are currently just playing around with the
engine, please look at other examples first. 
This tutorials shows how to create a custom scene node and
how to use it in the engine. A custom scene node is needed,
if you want to implement a render technique, the 
engine is currently not supporting. For example you can write
a indoor portal based renderer or a advanced terrain scene 
node with it. With creating custom scene nodes, you can 
easily extend the LTE Game Engine and adapt it to your
needs.

I will keep the tutorial simple: Keep everything very
short, everything in one .cpp file, and I'll use the engine
here as in all other tutorials.

To start, I include the header files and use the engine namespace.
*/
#include <engine.h>
#include "../common.h"

using namespace engine;

/*
Here comes the most sophisticated part of this tutorial: 
The class of our very own custom scene node. To keep it simple,
our scene node will not be an indoor portal renderer nor a terrain
scene node, but a simple tetraeder, a 3d object consiting of 4
connected vertices, which only draws itself and does nothing more.

To let our scene node be able to be inserted into the 
Engine scene, the class we create needs only be derived from the
ISceneNode class and has to override some methods.
*/

class CSampleSceneNode : public scene::ISceneNode
{

	/*
	First, we declare some member variables. Some space to
	hold data for our tetraeder: The bounding box, 4 vertices, and
	the material of the tetraeder.
	*/
	core::aabbox3d<f32> Box;
	video::S3DVertex Vertices[4];
	video::SMaterial Material;


	/*
	The parameters of the constructor specify the parent of the scene node,
	a pointer to the scene manager, and an id of the scene node.
	In the constructor itself, we call the parent classes constructor,
	set some properties of the material we use to draw the scene nodem and 
	create the 4 vertices of the tetraeder we will draw later.
	*/

public:

	CSampleSceneNode(scene::ISceneNode* parent, scene::ISceneManager* mgr, s32 id)
		: scene::ISceneNode(parent, mgr, id)
	{
		Material.Wireframe = false;
		Material.Lighting = false;

		Vertices[0] = video::S3DVertex(0,0,10, 1,1,0, video::SColor(255,0,255,255), 0, 1);
		Vertices[1] = video::S3DVertex(10,0,-10, 1,0,0, video::SColor(255,255,0,255), 1, 1);
		Vertices[2] = video::S3DVertex(0,20,0, 0,1,1, video::SColor(255,255,255,0), 1, 0);
		Vertices[3] = video::S3DVertex(-10,0,-10, 0,0,1, video::SColor(255,0,255,0), 0, 0);

	/*
	The engine needs to know the bounding box of your scene node. 
	It will use it for doing automatic culling and other things. Hence we
	need to create a bounding box from the 4 vertices we use. 
	If you do not want the engine to use the box for automatic culling, 
	and/or don't want to create the box, you could also write
	AutomaticCullingEnabled = false;.
	*/
		Box.reset(Vertices[0].Pos);
		for (s32 i=1; i<4; ++i)
			Box.addInternalPoint(Vertices[i].Pos);
	}


	/*
	Before it is drawn, the OnPreRender() method of every scene node in the scene 
	is called by the scene manager. If the scene node wishes to draw itself,
	it may register itself in the scene manager to be drawn. This is necessary to
	tell the scene manager when it should call the ::render method. For example
	normal scene nodes render their content one after another, while
	stencil buffer shadows would like to be drawn after all other scene nodes. And
	camera or light scene nodes need to be rendered before all other scene 
	nodes (if at all).
	So here we simply register the scene node to get render normally. If we would like
	to let it be rendered like cameras or light, we would have to call
	SceneManager->registerNodeForRendering(this, SNRT_LIGHT_AND_CAMERA);
	After this, we call the OnPreRender-method of the base class ISceneNode,
	which simply lets also all the child scene nodes of this node register themselves.
	*/
	virtual void OnPreRender()
	{
		if (IsVisible)
			SceneManager->registerNodeForRendering(this);

		ISceneNode::OnPreRender();
	}

	/*
	In the render() method most of the interesting stuff happenes: The
	Scene node renders itself. We override this method and draw the
	tetraeder.
	*/
	virtual void render()
	{
		unsigned short indices[] = {	0,2,3, 2,1,3, 1,0,3, 2,0,1	};
		video::IVideoDriver* driver = SceneManager->getVideoDriver();

		driver->setMaterial(Material);
		driver->setTransform(video::ETS_WORLD, AbsoluteTransformation);
		driver->drawIndexedTriangleList(&Vertices[0], 4, &indices[0], 4);
	}

	/*
	At least, we create three small additional methods.
	GetBoundingBox() returns the bounding box of this scene node, 
	GetMaterialCount() returns the amount of materials in this scene node
	(our tetraeder only has one material), and getMaterial() returns the
	material at an index. Because we have only one material here, we can
	return the only one meterial, assuming that no one ever calls getMaterial()
	with an index greater than 0.
	*/
	virtual const core::aabbox3d<f32>& getBoundingBox() const
	{
		return Box;
	}

	virtual s32 getMaterialCount()
	{
		return 1;
	}

	virtual video::SMaterial& getMaterial(s32 i)
	{
		return Material;
	}	
};

/*
That's it. The Scene node is done. Now we simply have to start
the engine, create the scene node and a camera, and look at the result.
*/
int engineMain(unsigned int argc, void *argv )
{
  // setup psp callbacks
  setupPSP();

	// create device

	engineDevice *device =
		createDevice();
		

	// create engine and camera

	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr = device->getSceneManager();

	smgr->addCameraSceneNode(0, core::vector3df(0,-40,0), core::vector3df(0,0,0));

	/*
	Create our scene node. Note that it is dropped (->drop()) instantly after 
	we create it. This is possible because the scene manager now takes
	care of it. This is not nessecary, it would also be possible to drop it
	at the end of the program.
	*/

	CSampleSceneNode *myNode = 
		new CSampleSceneNode(smgr->getRootSceneNode(), smgr, 666);

	myNode->drop();

	/*
	To animate something in this boring scene consisting only of one tetraeder,
	and to show, that you now can use your scene node like any other scene
	node in the engine, we add an animator to the scene node, which rotates
	the node a little bit.
	*/

	scene::ISceneNodeAnimator* anim = 
		smgr->createRotationAnimator(core::vector3df(0.8f, 0.f, 0.8f));

	myNode->addAnimator(anim);
	anim->drop();

	/* 
	Now draw everything and finish.
	*/

	while(device->run())
	{
		driver->beginScene(true, true, video::SColor(0,100,100,100));

		smgr->drawAll();

		driver->endScene();
	}

	sceKernelExitGame();
	
	return 0;
}

