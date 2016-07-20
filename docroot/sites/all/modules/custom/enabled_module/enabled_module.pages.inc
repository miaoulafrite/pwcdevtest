<?php
/**
 * @file
 * enabled_module.pages.inc
 */

/**
 * Implements hook_form().
 */
function enabled_module_calculator_form($form, &$form_state) {

  $calculation_string = !empty($form_state['values']['calculation']) ? $form_state['values']['calculation'] : 0;

  $form['#ajax'] = array(
    'enabled' => TRUE
  );

  $form['calculation'] = array(
    '#type' => 'textfield',
    '#title' => '',
    '#default_value' => $calculation_string,
    '#prefix' => '<div id="calculation-result">',
    '#suffix' => '</div>',
  );

  $form['operators'] = array(
    '#title' => t('Operators'),
    '#type' => 'radios',
    '#options' => array(
      '+' => '+',
      '-' => '-',
      '*' => '*',
      '/' => '/',
    ),
  );

  $form['numbers'] = array(
    '#title' => t('Numbers'),
    '#type' => 'radios',
    '#options' => drupal_map_assoc(range(0, 9))
  );

  $form['#attached']['js'] = array(
    drupal_get_path('module', 'enabled_module') . '/js/enabled_module.js' => array(
      'type' => 'file',
    ),
  );

  $form['#attached']['css'] = array(
    drupal_get_path('module', 'enabled_module') . '/css/enabled_module.css' => array(
      'type' => 'file',
    ),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#ajax' => array(
      'callback' => 'enabled_module_calculator_form_callback',
      'wrapper' => 'calculation-result',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  return $form;
}

/**
 * AJAX hanlder for the enabled_module_calculator_form form.
 */
function enabled_module_calculator_form_callback($form, &$form_state) {

  $calculation_result = $calculation_string = !empty($form_state['values']['calculation']) ? $form_state['values']['calculation'] : 0;

  if ($calculation_string) {
    // The last character is always the next operator.
    $operator = substr($calculation_string, -1);

    // The operation to be performed.
    $operation = substr($calculation_string, 0, -1);

    $calculation_result = enabled_module_calculator_calculate_from_string($operation);
  }

  $form['calculation']['#value'] = $calculation_result . $operator;
  return $form['calculation'];
}