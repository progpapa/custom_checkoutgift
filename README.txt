This module allows users to enter a gitf message when checking out.
This message will be attached to their order and a new line item will also be
added.

1. Creates a new:
   - checkout pane, called 'Gift Service'
   - line item type, called 'Gift Service'
   - price component, called - yes - 'Gift Service'
   - field (called 'Gift Message') and attaches it to the order
2. Allows administrators to configure the pane at
   admin/commerce/config/checkout/form/pane/custom_checkoutgift by setting the
   price for the line item.
3. When user is checking out, a message can be entered is gift service is
   required.
4. Admins will see the message when editing the order.
