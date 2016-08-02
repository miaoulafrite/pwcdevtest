<?php
/**
 * @file
 * calculator.pages.inc
 */

/**
 * Calculator page callback.
 */
function calculator_page() {
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'calculator') . '/js/calculator.js',
  );

  $form['markup'] = array(
    '#markup' => '<h3>Enter a number into each box below and select an operator to perform the calculation.</h3>',
  );

  $form['number_one'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter a number.'),
    '#size' => 30,
    '#attributes' => array(
      'class' => array('num', 'num1'),
    ),
  );

  $form['number_two'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter a number.'),
    '#size' => 30,
    '#attributes' => array(
      'class' => array('num', 'num2'),
    ),
  );

  $form['operator'] = array(
    '#type' => 'select',
    '#title' => t('Operator'),
    '#options' => array(
      '' => t('None'),
      '+' => t('+'),
      '-' => t('-'),
      '/' => t('/'),
      '*' => t('*'),
    ),
    '#default_value' => 0,
    '#attributes' => array(
      'class' => array('operator'),
    ),
  );

  $form['total'] = array(
    '#type' => 'textfield',
    '#title' => t('Total'),
    '#size' => 30,
    '#attributes' => array(
      'class' => array('total'),
      'readonly' => 'readonly',
    ),
  );

  return $form;
}
