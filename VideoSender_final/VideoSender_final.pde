import processing.video.*;
import ipcapture.*;

import javax.imageio.*;
import java.awt.image.*; 

// This is the port we are sending to
//int clientPort = 9100; 
int clientPort1 = 11999; 
int clientPort2 = 12000;
//int clientPort3 = 12001;
// This is our object that sends UDP out
DatagramSocket ds1; 
DatagramSocket ds2;
//DatagramSocket ds3;
// Capture object
IPCapture cam;

PImage img; 

void setup() {
  size(320,240);
  // Setting up the DatagramSocket, requires try/catch
  try {
    ds1 = new DatagramSocket();
  } catch (SocketException e) {
    e.printStackTrace();
  }
  
  try {
    ds2 = new DatagramSocket();
  } catch (SocketException e) {
    e.printStackTrace();
  }
  
//    try {
//    ds3 = new DatagramSocket();
//  } catch (SocketException e) {
//    e.printStackTrace();
//  }
  
  // Initialize Camera
  //cam = new IPCapture(this, "http://192.168.130.96/image", "", "");
  cam = new IPCapture(this, "http://76.169.250.29/anony/mjpg.cgi", "", "");
  cam.start();
  
  //img = loadImage("http://192.168.130.96/image");
}

//void captureEvent( IPCapture c ) {
//  c.read();
//  // Whenever we get a new image, send it!
//  //broadcast(c);
//  broadcast(c);
//}

void draw() {
  //image(cam,0,0);
  if (cam.isAvailable()) {
    cam.read();
    broadcast1(cam);
    broadcast2(cam);
    //broadcast3(cam);
    image(cam,0,0);
  }
}


// Function to broadcast a PImage over UDP
// Special thanks to: http://ubaa.net/shared/processing/udp/
// (This example doesn't use the library, but you can!)
void broadcast1(PImage img) {

  // We need a buffered image to do the JPG encoding
  BufferedImage bimg = new BufferedImage( img.width,img.height, BufferedImage.TYPE_INT_RGB );

  // Transfer pixels from localFrame to the BufferedImage
  img.loadPixels();
  bimg.setRGB( 0, 0, img.width, img.height, img.pixels, 0, img.width);

  // Need these output streams to get image as bytes for UDP communication
  ByteArrayOutputStream baStream  = new ByteArrayOutputStream();
  BufferedOutputStream bos    = new BufferedOutputStream(baStream);

  // Turn the BufferedImage into a JPG and put it in the BufferedOutputStream
  // Requires try/catch
  try {
    ImageIO.write(bimg, "jpg", bos);
  } 
  catch (IOException e) {
    e.printStackTrace();
  }

  // Get the byte array, which we will send out via UDP!
  byte[] packet = baStream.toByteArray();

  // Send JPEG data as a datagram
  println("Sending datagram with " + packet.length + " bytes");
  try {
    ds1.send(new DatagramPacket(packet,packet.length, InetAddress.getByName("128.122.151.223"),clientPort1));
  } 
  catch (Exception e) {
    e.printStackTrace();
  }
}

// Function to broadcast a PImage over UDP
// Special thanks to: http://ubaa.net/shared/processing/udp/
// (This example doesn't use the library, but you can!)
void broadcast2(PImage img) {

  // We need a buffered image to do the JPG encoding
  BufferedImage bimg = new BufferedImage( img.width,img.height, BufferedImage.TYPE_INT_RGB );

  // Transfer pixels from localFrame to the BufferedImage
  img.loadPixels();
  bimg.setRGB( 0, 0, img.width, img.height, img.pixels, 0, img.width);

  // Need these output streams to get image as bytes for UDP communication
  ByteArrayOutputStream baStream  = new ByteArrayOutputStream();
  BufferedOutputStream bos    = new BufferedOutputStream(baStream);

  // Turn the BufferedImage into a JPG and put it in the BufferedOutputStream
  // Requires try/catch
  try {
    ImageIO.write(bimg, "jpg", bos);
  } 
  catch (IOException e) {
    e.printStackTrace();
  }

  // Get the byte array, which we will send out via UDP!
  byte[] packet = baStream.toByteArray();

  // Send JPEG data as a datagram
  println("Sending datagram with " + packet.length + " bytes");
  try {
    ds2.send(new DatagramPacket(packet,packet.length, InetAddress.getByName("128.122.151.79"),clientPort2));
  } 
  catch (Exception e) {
    e.printStackTrace();
  }
}

//// Function to broadcast a PImage over UDP
//// Special thanks to: http://ubaa.net/shared/processing/udp/
//// (This example doesn't use the library, but you can!)
//void broadcast3(PImage img) {
//
//  // We need a buffered image to do the JPG encoding
//  BufferedImage bimg = new BufferedImage( img.width,img.height, BufferedImage.TYPE_INT_RGB );
//
//  // Transfer pixels from localFrame to the BufferedImage
//  img.loadPixels();
//  bimg.setRGB( 0, 0, img.width, img.height, img.pixels, 0, img.width);
//
//  // Need these output streams to get image as bytes for UDP communication
//  ByteArrayOutputStream baStream  = new ByteArrayOutputStream();
//  BufferedOutputStream bos    = new BufferedOutputStream(baStream);
//
//  // Turn the BufferedImage into a JPG and put it in the BufferedOutputStream
//  // Requires try/catch
//  try {
//    ImageIO.write(bimg, "jpg", bos);
//  } 
//  catch (IOException e) {
//    e.printStackTrace();
//  }
//
//  // Get the byte array, which we will send out via UDP!
//  byte[] packet = baStream.toByteArray();
//
//  // Send JPEG data as a datagram
//  println("Sending datagram with " + packet.length + " bytes");
//  try {
//    ds3.send(new DatagramPacket(packet,packet.length, InetAddress.getByName("192.168.130.242"),clientPort3));
//  } 
//  catch (Exception e) {
//    e.printStackTrace();
//  }
//}
