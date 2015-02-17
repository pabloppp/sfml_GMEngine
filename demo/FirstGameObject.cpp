#include "FirstGameObject.hpp"
#include "MyGame.hpp"
#include "CustomScript.hpp"

void FirstGameObject::setup(){
    
    //AÑADIMOS LOS SCRIPTS Y SE CUSTOMIZAN SI ES NECESARIO
    addTag("tag1");
    CustomScript *script1 = new CustomScript();
    addComponent(script1);
    //definimos valores inciales para el script
    script1->contador = 3;
    script1->interruptor = true;
    
}


