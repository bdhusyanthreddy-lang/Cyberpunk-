# Enhanced Starfield Themes

This file provides multiple starfield themes that can be used to create visually stunning starfield effects.

## Theme Support
We have implemented the following themes:

1. **Retro Theme**  
   - **Colors**: Light Yellow and Dark Blue  
   - **Star Character**: `*`  
   - **Visual Style**: Classic retro starfield with slower speeds.

2. **Neon Theme**  
   - **Colors**: Bright pink and Electric Blue  
   - **Star Character**: `✦`  
   - **Visual Style**: Fast-moving stars with a glowing effect.

3. **Cosmic Theme**  
   - **Colors**: Purple and Deep Black  
   - **Star Character**: `★`  
   - **Visual Style**: Stars twinkling at varying rates.

4. **Aurora Theme**  
   - **Colors**: Green and Blue gradients  
   - **Star Character**: `➹`  
   - **Visual Style**: Soft waves of stars like the Northern Lights.

5. **Matrix Theme**  
   - **Colors**: Green on Black with trailing effects  
   - **Star Character**: `░`  
   - **Visual Style**: Falling code-style stars.

6. **Cyberpunk Theme**  
   - **Colors**: Neon Green and Purple  
   - **Star Character**: `❂`  
   - **Visual Style**: Fast-paced, vibrant stars with an urban feel.

## Usage Instructions
To use these themes, instantiate the desired theme class in your application and invoke the draw method.

## Example Code

```c++
#include <iostream>

class Starfield {
public:
    void setTheme(std::string theme);
    void draw();
};

int main() {
    Starfield starfield;
    starfield.setTheme("neon"); // Can be 'retro', 'neon', 'cosmic', 'aurora', 'matrix', 'cyberpunk'
    starfield.draw();
    return 0;
}
```  

This code is a prototype for using the theme classes in applications.