package rmit.springboot_demo.user_profile;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/hello")
public class UserProfileController {
    @Autowired
    private UserProfileService userProfileService;
    @GetMapping("")
        public String sayHello(){
            return userProfileService.sayHello();
        }
    @GetMapping("/{name}")
        public String sayHelloName(@PathVariable String name){
            return userProfileService.sayHelloName(name);
        }
    // @GetMapping ("/user/{userId}")
    // public ResponseEntity<UserProfileModel> findUserById(@PathVariable int userId){
    //     UserProfileModel user = userProfileService.getUserInfoById(userId);
    //     // return userProfileService.getUserInfoById(userId);
    //     return new ResponseEntity<UserProfileModel>(
    //         user, HttpStatus.OK
    //     );
    // }
    @GetMapping ("/user/shipping_info/{userId}")
    public ResponseEntity<UserShippingAddress> getShippingInfo(@PathVariable int userId){
        UserShippingAddress user = userProfileService.getUserInfoById(userId);
        // return userProfileService.getUserInfoById(userId);
        return new ResponseEntity<UserShippingAddress>(
            user, HttpStatus.OK
        );
    }
}
