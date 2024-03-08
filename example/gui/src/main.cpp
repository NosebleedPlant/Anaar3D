
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Anaar3D/Core.hpp>
#include <stdio.h>

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main(){
    Context context;
    context.create("learn",800,600);
    
    Model test = Model(new Mesh::QuadMesh(), new AnaarGL::Shader());
    
    while(context.check_open()){
        context.clear();
        context.render(&test);
    }
    context.close();
    return 0;
}

/*
    camera = camera();
    model = model(mesh(),material());
    scene.add(model);
    while (context_open){
        //move stuff around
        renderer.render(scene,camera,*target_buffer);
        renderer.composite(*target_buffer,shader);
        context.update(*target_buffer);
    }
*/

//other primitives: pyramid, cone, torus, box, plane, sphere, circle




/*
what i did:
    -ran the pilots 
        -make it clear that prof wont know
        -recruit online
        -include the protocol number
        -in the consent form
    -set up r and worked on writing scripts to convert data in to the shapes that it expects for the anova
    -was supposed to run one more pilot but the particpant is a bit unwell today so they asked to rechedule to wed

what ill do:
    -poster today
    -pilot study

Questions:
    -can i recruit from 302 thi year since im not a TA?
    -game dev club might work and ill also ask prof guzdial if i can recruit from their classes

Keyboard discussion:
    -potential research directions
        -ime development
        -exploration of dialetic variation
        -google translate prototype


        -soft keyboard like urdu on mobile as a visual support or stickers on the keyboard
        -initial interviews and questionare with people in both canada and pakistan then talk about text entery. Difference between people of rasisign
        -also look at data sets
        -contact authors about the data ethics

    -depending on what we do i could present on may grant for literacy 
        -poster describing overall problem
        -charachterize the state of the feild
        -probably worth doing the NLP course
            -machine learning helps with nlp 466 naive bays
            -covers basic linguistics
            -meta language around linguistics
            -hidde markov ngrams
            -chatbots
            -finite state autmaton
            -reg ex
            -grammar for compilers and syntax tree
        -for now look at litertature and smethods
*/