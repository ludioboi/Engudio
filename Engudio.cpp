#include "core/vector3.h"
#include "core/transform.h"
#include "core/quaternion.h"
#include "game/game_state_manager.h"
#include <iostream>
#include <format>
#include <windows.h> 
#include <glad/glad.h> 
#include <GLFW/glfw3.h>

using namespace std;

#define VOXEL_SIZE 2
#define FLLSCR false


bool DEBUG = true;


class Voxel {
public:
    Transform pos;
    vector<Transform> points;
    Voxel(Transform pos) {
        this->pos = pos;
        Transform t = Transform(2, 2, 0);
        t.setParent(&pos);
        this->points.push_back(t);
        t = Transform(-2, 2, 0);
        t.setParent(&pos);
        this->points.push_back(t);
        t = Transform(2, -2, 0);
        t.setParent(&pos);
        this->points.push_back(t);
        t = Transform(-2, -2, 0);
        t.setParent(&pos);
        this->points.push_back(t);
    }
};

//Debug INFO
template<class T>
void D_LOG (const T& msg){
    if (!DEBUG) return;
    cout << "[INFO] " << msg << endl;
}

//Debug ERROR
template<class T>
void D_ERR(const T& msg) {
    if (!DEBUG) return;
    cerr << "[ERR] " << msg << endl;
}


GLFWwindow* mainWindow;

//Sets all Callbacks and Handlers
void initCallbacks() {
    glfwSetWindowSizeCallback(mainWindow, [](GLFWwindow* wind, int width, int height) {
        D_LOG(format("Set Screen Size to {0} x {1}", width, height));
        });
    glfwSetWindowFocusCallback(mainWindow, [](GLFWwindow* win, int focused) {
       
        });
}


int main() {
    

    //TEST Rotatioon
    Voxel v = Voxel(Transform(5, 5, 5));
    v.pos.setRotation(Quaternion(20, 0, 0));
    for (int i = 0; i < v.points.size(); i++) {
        Transform c = v.points[i];
        Vector3 vec = c.getGlobalVector3();
        cout << vec.getX() << " / " << vec.getY() << " / " << vec.getZ() << endl;
    }
    
    //Creates a Console if needed
    if (DEBUG) {
        AllocConsole();
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);

        std::cout.clear();
    }

    if (glfwInit()) {
        D_LOG("Loaded GLFW3");
    } else {
        D_ERR("Could not load GLFW3");
    }

    //Gets Primary Monitor to show the window
    GLFWmonitor* mon = glfwGetPrimaryMonitor();
    const GLFWvidmode* vidMode = glfwGetVideoMode(mon);

    mainWindow = glfwCreateWindow(640, 480, "Engudio", FLLSCR ? mon : NULL, NULL);
    if (mainWindow) {
        D_LOG("Created Window");
    } else {
        D_ERR("Could not create a Window");
    }


    //Init all callbacks
    initCallbacks();


    //fits size of window to screen size
    if (FLLSCR) {
        glfwSetWindowSize(mainWindow, vidMode->width, vidMode->height);
    }
    
    

    //Sets window rules
    glfwSetWindowSizeLimits(mainWindow, 640, 480, GLFW_DONT_CARE, GLFW_DONT_CARE);

    
    glfwMakeContextCurrent(mainWindow);

    while (!glfwWindowShouldClose(mainWindow)) {
        
        glfwSwapBuffers(mainWindow);
        glfwPollEvents();
        
    }
    glfwTerminate();
    return 0;
}

