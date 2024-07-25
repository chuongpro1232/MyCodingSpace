package rmit.springboot_demo.user_profile;

import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Service;
import org.springframework.web.bind.annotation.PathVariable;

@Service

public class UserProfileService {

    @Autowired UserProfileRespritory userProfileRespritory;
    public String sayHello(){
        return "Hello World";
    }
    public String sayHelloName(@PathVariable String name){
            return "Hello " + name;
        }
    public UserShippingAddress getUserInfoById(int id){
        Optional<UserProfileModel> userModelOpt =
        userProfileRespritory.findUserById(id);
        if (userModelOpt.isPresent()){
            UserShippingAddress user = userModelOpt.get();
            return user; 
        //     return """
        //     Name: %s, </br>
        //     ID: %d, </br>
        //     Address: %s </br>
        // """.formatted(
        //    user.getName(),
        //    user.getId(),
        //    user.getAddress()
        // );
        }
       else {
        return UserProfileModel.getDefaultInvalidUser();
       }
                
                
    }
}
