/*
 * Title  : Airplane on cloud
 * Author : Girish Patil 
 
 */

#include "CarRacing.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    
  //  scene->getPhysicsWorld()->setGravity(Vec2(2,4));
    //scene->addChild(scene);
    scene->addChild(layer);
    
  
    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    auto sprite1 = Sprite::create("cloud.jpg");
    sprite1->setPosition(200,160);
    this->addChild(sprite1,0);
    
    sprite = Sprite::create("Airplane.png");
    //sprite = Sprite::create("comanche.gif");
    //sprite->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
    sprite->setPosition(150,220);
    this->addChild(sprite, 0);
    
    this->scheduleUpdate();
    
    return true;
}

void HelloWorld::update(float delta){
   auto position = sprite->getPosition();
   position.x -= 20 * delta;
   if (position.x  < 0 - (sprite->getBoundingBox().size.width / 2))
      position.x = this->getBoundingBox().getMaxX() + sprite->getBoundingBox().size.width/2;
   
   sprite->setPosition(position);
}