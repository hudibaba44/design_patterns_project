#include "ImageComponent.h"
#include <QDebug>
ImageComponent::ImageComponent()
{

}

void ImageComponent::update(Character *character)
{
    std::vector<std::string> sprites = character->getSprites();
    if(character->getHealth() == 0 || sprites.size() == 1){
        character->setSprite(sprites[0]);
        return;
    }
//    qDebug() << "character->getHealth():"<<character->getHealth();
//    qDebug() << "character->getMaxHealth():"<<character->getMaxHealth();
    int percentage = (character->getHealth()*100)/character->getMaxHealth();
    int numberOfSprites = sprites.size() -1;
    int index = percentage/(100/numberOfSprites) + 1;
    if(index>=static_cast<int>(sprites.size())){
        index = sprites.size()-1;
    }
//    qDebug() << "index:"<<index;
    character->setSprite(sprites[index]);
}
