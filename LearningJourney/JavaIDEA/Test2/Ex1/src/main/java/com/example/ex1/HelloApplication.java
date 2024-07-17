/*
  RMIT University Vietnam
  Course: INTE2512 Object-Oriented Programming
  Semester: 2023A
  Assessment: Test 2
  Author: Tran Thanh Tu
  ID: S3957386
  Created  date: 13/5/2023
  Acknowledgement: https://stackoverflow.com/questions/15041760/javafx-open-new-window
  https://www.w3schools.com/java/java_files_create.asp
  https://beginnersbook.com/2014/01/how-to-write-to-file-in-java-using-bufferedwriter/
  OpenAI
*/

package com.example.ex1;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class HelloApplication extends Application {
    private TextField nameInputField, addressInputField, ageInputField, occupationInputField;
    @Override
    public void start(Stage stage) throws Exception {
        BorderPane bdPane = new BorderPane(); //Create Outter Layout
        ImageView logo = new ImageView("https://upload.wikimedia.org/wikipedia/commons/thumb/5/51/RMIT_University_Logo.svg/2560px-RMIT_University_Logo.svg.png"); //Insert Image
        logo.setFitHeight(100); //Limit the height to 100 so that the image would be not too big
        logo.setPreserveRatio(true);
        bdPane.setCenter(logo);//insert logo into the app

        HBox hbox = new HBox(30);
        hbox.setAlignment(Pos.CENTER);//set center for both of the button
        Button desButton = new Button("Description");//create Button
        Button formButton = new Button ("Form");
        hbox.getChildren().addAll(desButton,formButton);//add button into pane
        bdPane.setBottom(hbox); //add pane to outter Pane

        nameInputField = new TextField();//create textfield for later use
        addressInputField = new TextField();
        ageInputField = new TextField();
        occupationInputField = new TextField();

        Scene scene = new Scene(bdPane);
        stage.setTitle("Application");
        stage.setScene(scene);
        stage.show();
        desButton.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent event) {
                Parent root;
                try {
                    Button returnButton = new Button("Return To Main Screen");//Button for returning
                    BorderPane DesbdPane = new BorderPane();//pane for showing out Description
                    DesbdPane.setCenter(new Text("This is the app that will save your personal information,\n That was developed by Tran Thanh Tu - S3957386,\n a 2nd year Student at RMIT University in Vietnam"));//text
                    Scene DesScene = new Scene(DesbdPane,300,300);
                    stage.setScene(DesScene);
                    DesbdPane.setBottom(returnButton);
                    DesbdPane.setAlignment(returnButton, Pos.CENTER);//set the location of the button to center
                    stage.setTitle("Desciption");
                    stage.setScene(DesScene);
                    stage.show();
                    returnButton.setOnAction(new EventHandler<ActionEvent>() { //if the return button was pressed return to the main screen which is the splash one
                        public void handle(ActionEvent event) {
                            Parent root;
                            try {

                                stage.setScene(scene);
                                stage.setTitle("Application");
                                stage.show();

                            }
                            catch (Exception e) {
                                e.printStackTrace();
                            }
                        }
                    });
                }
                catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });

        formButton.setOnAction(new EventHandler<ActionEvent>() { //if form button was pressed open form window
            public void handle(ActionEvent event) {
                Parent root;
                try {

                    Button submitButton = new Button("Submit");//created submit button

                    GridPane formScreen = new GridPane();
                    formScreen.setAlignment(Pos.CENTER);
                    formScreen.setVgap(10); //set space
                    formScreen.setHgap(10);
                    formScreen.setPadding(new Insets(10));

                    formScreen.add(new Label("Name:"), 0, 0); //adding Labels
                    formScreen.add(nameInputField, 1, 0);
                    formScreen.add(new Label("Address:"), 0, 1);
                    formScreen.add(addressInputField, 1, 1);
                    formScreen.add(new Label("Age:"), 0, 2);
                    formScreen.add(ageInputField, 1, 2);
                    formScreen.add(new Label("Occupation:"), 0, 3);
                    formScreen.add(occupationInputField, 1, 3);
                    formScreen.add(submitButton, 1, 4);

                    Scene DesScene = new Scene(formScreen,300,300);
                    stage.setScene(DesScene);
                    stage.setTitle("Form");
                    stage.setScene(DesScene);
                    stage.show();
                    submitButton.setOnAction(e -> { //if the submit button was pressed bump out the window that said Data successfully Saved
                        if (validateInput()) {
                            try (BufferedWriter writer = new BufferedWriter(new FileWriter("userInfo.txt", true))) {  //Save into the file ame userInfo

                                writer.write("Name: " + nameInputField.getText() +
                                        ", Address: " + addressInputField.getText() +
                                        ", Age: " + ageInputField.getText() +
                                        ", Occupation: " + occupationInputField.getText() + "\n");
                                Alert successAlert = new Alert(Alert.AlertType.INFORMATION);
                                successAlert.setTitle("Success");
                                successAlert.setHeaderText(null);
                                successAlert.setContentText("Data successfully saved!");
                                successAlert.showAndWait();
                                stage.setScene(scene);
                            } catch (IOException ioException) {
                                ioException.printStackTrace();
                            }
                        }
                    });
                }
                catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });

    }

    private boolean validateInput() {
        String name = nameInputField.getText();
        String address = addressInputField.getText();
        String age = ageInputField.getText();
        String occupation = occupationInputField.getText();
        return true;
    }
    public static void main(String[] args) {
        launch();
    }
}