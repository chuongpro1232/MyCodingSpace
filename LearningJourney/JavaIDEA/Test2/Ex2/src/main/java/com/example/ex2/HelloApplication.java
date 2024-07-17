/*
  RMIT University Vietnam
  Course: INTE2512 Object-Oriented Programming
  Semester: 2023A
  Assessment: Test 2
  Author: Tran Thanh Tu
  ID: S3957386
  Created  date: 13/5/2023
  Acknowledgement:
  https://docs.oracle.com/javase/8/javafx/api/javafx/beans/binding/Bindings.html
  http://www.java2s.com/ref/java/javafx-circle-draw-random-circles-with-connecting-lines.html
  https://skills421.com/2014/08/03/using-javafx8-to-drag-connected-shapes/
  OpenAI
*/
package com.example.ex2;

import javafx.application.Application;
import javafx.beans.binding.Bindings;

import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.text.Text;
import javafx.stage.Stage;



public class HelloApplication extends Application {
    @Override
    public void start(Stage stage) {
        Pane mainPane = new Pane();// Create a pane to hold all elements

        Circle circle1 = new Circle(90, 90, 11); // Create the first circle at (90, 90) with radius 11
        circle1.setFill(Color.BLACK);//the color of the inner part would be black
        circle1.setStroke(Color.WHITE);//The color of the line of the circle would be white

        Circle circle2 = new Circle(130, 45, 11);// Create the second circle at (130, 45) with radius 11
        circle2.setFill(Color.GRAY);//GRAY COLOR
        circle2.setStroke(Color.BLACK);//BLACK LINE

        Line connectingLine = new Line();//creating Line that connect to circle together
        connectingLine.startXProperty().bind(circle1.centerXProperty());
        connectingLine.startYProperty().bind(circle1.centerYProperty());
        connectingLine.endXProperty().bind(circle2.centerXProperty());
        connectingLine.endYProperty().bind(circle2.centerYProperty());

        Text distanceText = new Text();// Create a text object to display the distance between the two circles
        distanceText.xProperty().bind(connectingLine.startXProperty().add(connectingLine.endXProperty()).divide(2));
        distanceText.yProperty().bind(connectingLine.startYProperty().add(connectingLine.endYProperty()).divide(2));
        distanceText.textProperty().bind(Bindings.createStringBinding(() -> {

            double dx = circle1.getCenterX() - circle2.getCenterX(); // Calculate the distance between the two circles
            double dy = circle1.getCenterY() - circle2.getCenterY();
            double distance = Math.sqrt(dx * dx + dy * dy);
            return String.format("%.2f", distance); //print it out and rounded it to 2 decimal
        }, circle1.centerXProperty(), circle1.centerYProperty(), circle2.centerXProperty(), circle2.centerYProperty()));


        circle1.setOnMouseDragged(e -> { //drag functionality of the circle
            circle1.setCenterX(e.getX());
            circle1.setCenterY(e.getY());
        });

        circle2.setOnMouseDragged(e -> {
            circle2.setCenterX(e.getX());
            circle2.setCenterY(e.getY());
        });

        // Add all components to the pane
        mainPane.getChildren().addAll(connectingLine, distanceText, circle1, circle2);

        // Create a scene, add the pane to the scene, set the scene on the stage
        Scene mainScene = new Scene(mainPane, 600, 400);
        stage.setTitle("Circle Drag Application");
        stage.setScene(mainScene);
        stage.show();
    }

    public static void main(String[] args) {
        // Launch the JavaFX application
        launch(args);
    }


}