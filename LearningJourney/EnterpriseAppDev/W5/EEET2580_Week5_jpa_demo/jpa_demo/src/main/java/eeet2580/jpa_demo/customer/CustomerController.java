package eeet2580.jpa_demo.customer;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;


@RestController
@RequestMapping("/customer")
public class CustomerController {

    @Autowired
    private CustomerService customerService;

    // *********** Uncomment the following code when your JPA is ready ***********

    // @GetMapping("/{id}")
    // CustomerInfo getCustomerInfoById(@PathVariable int id) {
    //     return customerService.getCustomerInfoById(id);
    // }

    // @PostMapping("")
    // CustomerInfo createCustomerInfoById(@RequestBody CustomerInfo customerData) {
    //     return customerService.createCustomerInfoById(customerData);
    // }

}