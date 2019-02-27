package communication;

import java.util.Scanner;

import javax.sound.sampled.Port;

import jssc.SerialPortException;

public class PCToMorseCode {
	private boolean debug;  // Indicator of "debugging mode"
	
 // This function can be called to enable or disable "debugging mode"
	void setDebug(boolean mode) {
		debug = mode;
	}	
	
	public static void main(String[] args) throws SerialPortException {		
		// TODO:  Fix this: 
		//           a) Uncomment to create a SerialComm object
		//           b) Update the "the port" to refer to the serial port you're using
		//              (The port listed in the Arduino IDE Tools>Port menu.		
		//           c) Deal with the unresolved issue
		 SerialComm port = new SerialComm("/dev/cu.usbserial-DN03FDMZ");

		
		// TODO: Complete section 6 of the Studio (gather sanitized user input
		//       and send it to the Arduino)
		 while (true) {
		//		
			    Scanner reading = new Scanner (System.in); 
			    
			    String neck = reading.nextLine(); 
			    char [] nex = new char [neck.length()]; 
			  
			    for (int i = 0; i < neck.length(); i++) {
			    	nex[i] = neck.charAt(i); 
			    	port.writeByte((byte)nex[i]);
			    }
			    
			    
			}
	}



     
    
     
     
     
}
