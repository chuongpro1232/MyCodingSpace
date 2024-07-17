module hehe.ex4 {
    requires javafx.controls;
    requires javafx.fxml;


    opens hehe.ex4 to javafx.fxml;
    exports hehe.ex4;
}