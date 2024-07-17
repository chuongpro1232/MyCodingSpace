package com.example.testing;


import javafx.application.Application;
import javafx.application.Platform;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.HBox;
import javafx.geometry.Insets;

import java.io.File;
import java.util.ArrayList;

public class HelloApplication extends Application {
    @Override
    public void start(Stage primaryStage) {
        VBox vbox = new VBox(5);
        // Create a HBox pane
        HBox pane = new HBox(5);
        pane.setPadding(new Insets(5, 5, 5, 5));
        // Add nodes to pane
        setCards(pane, getCards());

        HBox paneForButtons = new HBox(5);
        paneForButtons.setAlignment(Pos.CENTER);

        // Create buttons
        Button dealButton = new Button("Deal");
        Button exitButton = new Button("Exit");

        // Place buttons in HBox
        paneForButtons.getChildren().addAll(dealButton, exitButton);

        // Create a border pane
        BorderPane bPane = new BorderPane();
        bPane.setCenter(pane);
        bPane.setBottom(paneForButtons);

        // Create and register handlers
        dealButton.setOnAction(actionEvent -> {
            pane.getChildren().clear();
            setCards(pane, getCards());
        });
        exitButton.setOnAction(actionEvent -> {
            Platform.exit();
        });

        vbox.getChildren().addAll(pane, bPane);
        // Create a scene and place it in the stage
        Scene scene = new Scene(vbox, 300, 200);
        primaryStage.setTitle("W4_Q4"); // Set the stage title
        primaryStage.setScene(scene); // Place the scene in the stage
        primaryStage.show(); // Display the stage
    }

    private void setCards(Pane pane, ArrayList<Integer> cards) {

        for (int i = 0; i < 3; i++) {
            pane.getChildren().add(new ImageView(new Image("file:cards" + File.separator +
                    cards.get(i) + ".png")));
        }
    }

    /**
     * Returns a list with numbers 1-52 stored in random order
     */
    private ArrayList<Integer> getCards() {
        ArrayList<Integer> cards = new ArrayList<>();
        for (int i = 0; i < 52; i++) {
            cards.add(i + 1);
        }
        java.util.Collections.shuffle(cards);
        return cards;
    }
}