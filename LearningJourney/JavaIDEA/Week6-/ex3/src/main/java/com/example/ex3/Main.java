package com.example.ex3;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.scene.shape.Rectangle;
import javafx.geometry.Insets;
import javafx.scene.text.Text;



public class Main extends Application {


    @Override
    public void start(Stage stage) throws Exception {
        FXMLLoader fxmlLoader = new FXMLLoader(Main.class.getResource("hello-view.fxml"));
        double[] grade = {20,10,30,40};
        int height = 40;
        int width = 120;
        GridPane Gpane = new GridPane();
        StackPane pane = new StackPane();
        pane.setPadding(new Insets(200, 15, 5, 15));
        HBox hbox = new HBox(20);
        hbox.setAlignment(Pos.BOTTOM_CENTER);
        BorderPane borderPane = new BorderPane();


        Rectangle Project = new Rectangle (width,height*(grade[0]/10));
        Project.setFill(Color.RED);


        Rectangle Quiz = new Rectangle (width,height*(grade[1]/10));
        Quiz.setFill(Color.BLUE);


        Rectangle Midterm = new Rectangle(width,height*(grade[2]/10));
        Midterm.setFill(Color.GREEN);


        Rectangle Final = new Rectangle(width,height*(grade[3]/10));
        Final.setFill(Color.YELLOW);

        Text projectText = new Text ("Project -- "+grade[0]+" %");
        Text quizText = new Text ("Quiz -- "+grade[1]+" %");
        Text midtermText = new Text ("midterm -- "+grade[2]+" %");
        Text finalText = new Text ("Final -- "+grade[3]+" %");

        hbox.getChildren().addAll(getVbox(projectText, Project),getVbox(quizText,Quiz),getVbox(midtermText,Midterm),getVbox(finalText,Final));
        pane.getChildren().add(hbox);





        Scene scene = new Scene(pane);

        stage.setTitle("ex3");
        stage.setScene(scene);
        stage.show();
    }
public VBox getVbox(Text t, Rectangle r) {
        VBox vBox = new VBox (10);
        vBox.setAlignment(Pos.BOTTOM_LEFT);
        vBox.getChildren().addAll(t,r);
        return vBox;
}
    public static void main(String[] args) {
        launch();
    }
}