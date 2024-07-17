package com.example.ex5;

import javafx.application.Application;

import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.io.IOException;

public class HelloApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        Pane pane = new Pane();
        Circle c1 = new Circle (20 +Math.random()*201, 20+Math.random()*201,15);//Format kiểu center x center y và radius ở đây lấy số 20 + cho dù số random ra như nào thì hình tròn vẵn ở full trong pane

        c1.setFill(Color.WHITE);
        c1.setStroke(Color.BLACK);

        Circle c2 = new Circle (20 + Math.random()*201, 20 + Math.random()*201, 15);
        c2.setFill (Color.WHITE);
        c2.setStroke(Color.BLACK);

        Line line = new Line(c1.getCenterX(), c1.getCenterY(),c2.getCenterX(),c2.getCenterY());
        pane.getChildren().addAll(line,c1,c2,new Text(c1.getCenterX(),c1.getCenterY(),"1"),new Text (c2.getCenterX(),c2.getCenterY(),"2"));
        Scene scene = new Scene(pane);
        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}