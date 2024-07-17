package com.example.ex6;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

import java.io.IOException;

public class HelloApplication extends Application {
    @Override
    public void start(Stage stage) throws Exception {
        Pane pane = new Pane();
        double startX;
        double startY;
        double endingX;
        double endingY;


        Scene scene = new Scene( 320, 240);
        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();
    }
    public static void drawArrowLine(double startX,double startY,double endingX,double endingY,Pane pane){

    }
    public static void main(String[] args) {
        launch();
    }
}