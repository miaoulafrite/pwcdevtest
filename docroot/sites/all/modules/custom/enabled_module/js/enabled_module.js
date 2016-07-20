(function ($) {

  Drupal.enabledModuleCalculator = Drupal.enabledModuleCalculator || {};

  Drupal.behaviors.enabledModuleCalculator = {
    attach: function (context, settings) {

      $('.form-item-numbers input:radio').once().on('change', Drupal.enabledModuleCalculator.addValueToCalculation);

      // Operators are adding the number but also submitting the form.
      $('.form-item-operators input:radio').once().on('change', function (e) {
        var calculation = $('input[name=calculation]').val();

        if (calculation.length) {

          var previous_character = calculation.substr(calculation.length - 1);

          // We don't allow two operators in a row.
          if (Drupal.enabledModuleCalculator.hasOperator(previous_character )) {
            return;
          }

          // Has to be done before adding the value.
          var first_operator = !Drupal.enabledModuleCalculator.hasOperator(calculation);

          Drupal.enabledModuleCalculator.addValueToCalculation(e);

          // If is the first operator don't trigger the calculation.
          if (!first_operator) {
            $('#edit-submit').mousedown();
          }
        }
      });
    }
  };

  Drupal.enabledModuleCalculator.hasOperator = function (value) {
    return new RegExp(/[\+\-\*\/]+/).test(value);
  };

  Drupal.enabledModuleCalculator.addValueToCalculation = function (e) {
    var $calculation = $('input[name=calculation]');
    var value = $calculation.val();
    var new_value = $(e.currentTarget).val();
    if (value == 0 && !Drupal.enabledModuleCalculator.hasOperator(new_value)) {
      value = new_value;
    }
    else {
      value += new_value;
    }

    $calculation.val(value);
  }

})(jQuery);
