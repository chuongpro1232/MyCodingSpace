package com.example.demo;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class HelloApplication extends Application {
    @Override
    public void start(Stage primaryStage) {
        // Tạo một nút Button
        Button btn = new Button();
        btn.setText("Click me!");

        // Tạo một Pane và thêm nút Button vào đó
        StackPane rootPane = new StackPane();
        rootPane.getChildren().add(btn);

        // Tạo một Scene và chứa Pane trong đó
        Scene scene = new Scene(rootPane, 300, 250);

        // Đặt Scene cho Stage
        primaryStage.setScene(scene);

        // Đặt tiêu đề cho Stage
        primaryStage.setTitle("My JavaFX App");

        // Hiển thị Stage
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}