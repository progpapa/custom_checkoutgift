<?php

/**
 * @file
 * Defines a checkout pane for the gift service.
 *
 * - Defines a settings form to change the price.
 * - Defines the checkout pane form.
 */

/**
 * Implements base_settings_form().
 *
 * Allows changing the gift service price.
 */
function custom_checkoutgift_settings_form($checkout_pane) {

  $form['custom_checkoutgift_line_item_amount'] = array(
    '#type' => 'textfield',
    '#title' => t('Gift Service Price'),
    '#description' => t('For example: <b>5.43</b>.'),
    '#size' => 5,
    '#default_value' =>
      variable_get('custom_checkoutgift_line_item_amount', 3.95),
    '#required' => TRUE,
    // Hardcoding the currency...
    '#field_suffix' => 'EUR',
  );

  return $form;

} // custom_checkoutgift_settings_form

/**
 * Implements base_checkout_form()
 */
function custom_checkoutgift_checkout_form($form, $form_state, $checkout_pane, $order) {

  $wrapper = entity_metadata_wrapper('commerce_order', $order);
  $gift_message = $wrapper->field_customco_gift_message->value();

  $checkout_form['custom_checkoutgift_display']['message'] = array(
    '#type' => 'textarea',
    '#default_value' => empty($gift_message) ? '' : $gift_message,
    '#cols' => 40,
  );
  $checkout_form['custom_checkoutgift_display']['apply'] = array(
    '#type' => 'submit',
    '#value' => t('Apply'),
    '#name' => 'gift_apply',
    '#validate' => array('custom_checkoutgift_apply_validate'),
    '#submit' => array('custom_checkoutgift_apply_submit'),
    '#limit_validation_errors' => array(
      array('custom_checkoutgift_display', 'message')
    ),
  );
  $checkout_form['custom_checkoutgift_display']['remove'] = array(
    '#type' => 'submit',
    '#value' => t('Remove'),
    '#name' => 'gift_remove',
    '#submit' => array('custom_checkoutgift_remove_submit'),
    '#limit_validation_errors' => array(
      array('custom_checkoutgift_display', 'message')
    ),
  );

  // Hide the 'Remove' button if the gift service is not selected.
  if (!$gift_message) {
    $checkout_form['custom_checkoutgift_display']['remove']['#access'] = FALSE;
  } // if

  return $checkout_form;

} // custom_checkoutgift_checkout_form
