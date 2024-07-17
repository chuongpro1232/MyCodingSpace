package com.example.week6ex2;

import javafx.application.Application;

import javafx.scene.Scene;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;



public class HelloApplication extends Application {
    @Override
    public void start (Stage stage) throws Exception {
        GridPane Gpane = new GridPane ();
        for (int i = 0; i<8;i+=2){
            for (int j = 0; i < 8;i += 2){
                Rectangle white1 = new Rectangle(60,60);
                Gpane.add(white1,i,j);
                white1.setFill(Color.YELLOW);
            }
        }
        for (int i = 1; i < 8; i +=2){
            for (int j = 1; j < 8; j +=2){
                Rectangle white2 = new Rectangle(60,60);
                Gpane.add(white2,i,j);
                white2.setFill(Color.YELLOW);
            }
        }
        for (int i = 0; i < 8; i+=2){
            for (int j =1;j<8;j+=2){
                Rectangle black1 = new Rectangle(60,60);
                Gpane.add(black1,i,j);
                black1.setFill(Color.BLACK);
            }
        }
        for (int i = 1; i <8;i += 2){
            for (int j = 0;j < 8;j += 2){
                Rectangle black2 = new Rectangle(60,60);
                Gpane.add(black2,i,j);
                black2.setFill(Color.BLACK);
            }
        }

        Scene scene = new Scene(Gpane);
        stage.setScene(scene);
        stage.setTitle("Checkerboard");
        stage.show();
    }
    public static void main(String[] args) {
        launch();
    }
}