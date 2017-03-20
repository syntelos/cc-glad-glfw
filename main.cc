#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


static void key_callback(GLFWwindow*,int,int,int,int);


const GLuint WIDTH = 800, HEIGHT = 600;


int main(int argc, char** argv){
  char* progname = argv[0];

  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); 
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); 


  GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "hello", NULL, NULL);
  glfwMakeContextCurrent(window);
  if (window == NULL){
    std::cerr << progname << ": error: Failed to create GLFW window." << std::endl;
    glfwTerminate();
    return 1;
  }

  glfwSetKeyCallback(window, key_callback);

  if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
    std::cerr << progname << ": error: Failed to initialize OpenGL context." << std::endl;
    return 1;
  }


  glViewport(0, 0, WIDTH, HEIGHT);


  while (!glfwWindowShouldClose(window)){

    glfwPollEvents();


    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    glfwSwapBuffers(window);
  }


  glfwTerminate();
  return 0;
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode){

  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){

    glfwSetWindowShouldClose(window, GL_TRUE);
  }
}
