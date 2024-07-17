package hehe.ex4;

import javafx.application.Application;


import javafx.application.Platform;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.image.ImageView;
import javafx.scene.image.Image;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.text.Text;
import javafx.stage.Stage;


import java.io.File;
import java.lang.reflect.Array;
import java.util.Random;


public class HelloApplication extends Application {
    public static void main(String[] args) {
        launch();
    }

    @Override
    public void start(Stage stage) throws Exception {
        HBox hBox = new HBox();
        BorderPane outterPane = new BorderPane();
        showCards(hBox, getCards(outterPane));

        HBox BottomhBox = new HBox(20);
        BottomhBox.setAlignment(Pos.CENTER);
        Button dealButton = new Button("Deal");
        Button exitButton = new Button("Exit");
        BottomhBox.getChildren().addAll(dealButton, exitButton);

        dealButton.setOnAction(actionEvent -> {
            hBox.getChildren().clear();
            showCards(hBox, getCards(outterPane));
        });

        exitButton.setOnAction(actionEvent -> {
            Platform.exit();
        });


        outterPane.setTop(hBox);
        outterPane.setBottom(BottomhBox);

        Scene scene = new Scene(outterPane, 1566, 768);
        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();
    }

    private void showCards(HBox hBox, int[] cards) {
        for (int i = 0; i < 3; i++) {
            hBox.getChildren().add(new ImageView(new Image("file:cards" + File.separator + Array.get(cards, i) + ".png")));

        }
    }


    private int[] getCards(BorderPane pane) {
        int total = 0;
        int cards[] = new int[3];
        for (int i = 0; i < 3; i++) {
            Random random = new Random();
            cards[i] = random.nextInt(52) + 1;
            if (cards[i] >= 1 && cards[i] <= 13) {
                total += cards[i];
            } else if (cards[i] >= 14 && cards[i] <= 26) {
                total += cards[i] - 13;
            } else if (cards[i] >= 27 && cards[i] <= 39) {
                total += cards[i] - 26;
            } else {
                total += cards[i] - 39;
            }
            
        }

        Text t = new Text(total + " Points");
        pane.setCenter(t);
        return cards;
    }
}