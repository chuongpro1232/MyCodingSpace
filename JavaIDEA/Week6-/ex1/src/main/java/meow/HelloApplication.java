package meow.week6;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.image.ImageView;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

import java.io.IOException;

public class HelloApplication extends Application {

private final String [] URLS = {
        "https://cdn.britannica.com/41/4041-004-D051B135/Flag-Vietnam.jpg",
        "https://cdn.britannica.com/33/4833-004-828A9A84/Flag-United-States-of-America.jpg",
        "https://upload.wikimedia.org/wikipedia/commons/thumb/d/d9/Flag_of_Canada_%28Pantone%29.svg/1200px-Flag_of_Canada_%28Pantone%29.svg.png",
        "https://upload.wikimedia.org/wikipedia/commons/thumb/a/a5/Flag_of_the_United_Kingdom_%281-2%29.svg/1200px-Flag_of_the_United_Kingdom_%281-2%29.svg.png"
};

private ImageView [] createImages(){
    ImageView[] imgView = new ImageView[URLS.length];
    for (int i =0;i< URLS.length;i++){
        imgView[i] = new ImageView(URLS[i]);
        imgView[i].setFitWidth(300);
        imgView[i].setPreserveRatio(true);
        imgView[i].setSmooth(true);
    }
    return imgView;
}

private GridPane createdGridPane (ImageView[] imgView){
    GridPane gridPane = new GridPane();
    gridPane.add(imgView[0],1,1);
    gridPane.add(imgView[1],2,1);
    gridPane.add(imgView[2],1,2);
    gridPane.add(imgView[3],2,2);
    return gridPane;
}

    @Override
    public void start (Stage stage) throws Exception{
    ImageView[] imageViews = createImages();
    GridPane pane = createdGridPane(imageViews);

    Scene scene = new Scene (pane);
    stage.setTitle("4 Flags");
    stage.setScene(scene);
    stage.show();
    }
    public static void main(String[] args) {
        launch();
    }
}