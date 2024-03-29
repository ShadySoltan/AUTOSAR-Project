# AUTOSAR Project
 Full layered architecture AUTOSAR Project using SWS 4.0.3
______________________________________________________________________________________________________________

 ![alt text](E:\Projects\AUTOSAR-Project\README_IMGS\AUTOSAR.png)
______________________________________________________________________________________________________________

 Project Architecture:

 ![alt text](E:\Projects\AUTOSAR-Project\README_IMGS\ProjectArchitecture.png)

______________________________________________________________________________________________________________
Project Description:

In this project, we have leveraged the AUTOSAR (Automotive Open System Architecture) standards to
implement essential functionalities for embedded systems development. Specifically, 
we have implemented DIO (Digital Input/Output), PORT, and TIMER drivers adhering
to the AUTOSAR Software Specification (SWS) version 4.0.3.

Within this framework, we have constructed an Electronic Control Unit (ECU) layer, encompassing
fundamental components such as LED and BUTTON drivers. These drivers serve to interface with 
the hardware components, providing seamless integration with the underlying microcontroller 
unit.

Moreover, we have established a Service Layer that incorporates essential modules such as the 
scheduler and Development Error Tracer (DET). These modules are crucial for efficient task 
management and error detection, ensuring robust system performance.

The core functionality of the system revolves around the precise detection of button states.
The logic dictates that a button is considered pressed if it maintains a high state for a 
duration of 60 milliseconds, and conversely, it is considered released if it reads a low 
state for the same duration. To maintain system responsiveness, the output refresh cycle 
is set to occur every 40 milliseconds, ensuring timely updates.

Furthermore, we have provided essential support structures including compiler.h and platform
types tailored specifically for the TivaC board launchpad TM4C123GH6PM microcontroller unit
utilized in this project. These components facilitate seamless compatibility and 
optimization for the target hardware platform.

Additionally, we have implemented standard types and common macros files to streamline 
development and enhance code readability, adhering to best practices in embedded 
systems design.

Through meticulous implementation and adherence to AUTOSAR standards, this project 
delivers a robust and efficient framework for developing embedded systems, ensuring 
compatibility, reliability, and scalability.
______________________________________________________________________________________________________________
Files Structure:

Port Driver File Structure:
![alt text](E:\Projects\AUTOSAR-Project\README_IMGS\PORT_Driver_File_structure.png)
______________________________________________________________________________________________________________

Dio Driver File Structure:
![alt text](E:\Projects\AUTOSAR-Project\README_IMGS\DIO_Driver_File_structure.png)
______________________________________________________________________________________________________________