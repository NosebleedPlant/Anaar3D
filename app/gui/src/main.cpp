#include <Anaar3D/core.hpp>

int main(){
    Test test = Test();
    test.test_outpt();
    test.CreateAFContext_Raw();
    return 0;
}

//create context
//pass in renderer