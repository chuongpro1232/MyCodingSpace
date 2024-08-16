package eeet2580.jpa_demo.customer;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PatchMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/customer")
public class CustomerController {

    @Autowired
    private CustomerService customerService;

    // *********** Uncomment the following code when your JPA is ready ***********

    @GetMapping("/{id}")
    CustomerInfo getCustomerInfoById(@PathVariable int id) {
        return customerService.getCustomerInfoById(id);
    }

    @GetMapping("/{id}/nobalance")
    CustomerInfoBalance getCustomerInfoNobalance(@PathVariable int id) {
        return customerService.getCustomerInfoNobalance(id);
    }

    @PostMapping("")
    CustomerInfo createCustomerInfoById(@RequestBody CustomerInfo customerData) {
        return customerService.createCustomerInfoById(customerData);
    }

    @PatchMapping("/{id}/update-email")
    CustomerInfoBalance updCustomerInfoNobalance(@PathVariable int id, @RequestBody String emailRequest) {
        return customerService.updateCustomerInfoNobalance(id, emailRequest);
    }

}