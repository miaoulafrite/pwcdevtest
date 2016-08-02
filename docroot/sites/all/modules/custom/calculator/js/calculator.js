/**
 * Calculator JS
 */

(function ($) {

  Drupal.behaviors.calculateJS = {
    attach: function(context) {
      $('.operator', context).change(function () {
        // Only perform calculation when we have an operator.
        $op = $(this).val();
        if ($op != 0) {
          var num1 = Number($('.num1').val());
          var num2 = Number($('.num2').val());
          var total;

          switch ($op) {
            case '+':
              total = num1 + num2;
              break;
            case '-':
              total = num1 - num2;
              break;
            case '/':
              total = num1 / num2;
              break;
            case '*':
              total = num1 * num2;
              break;
          }

          $('.total').val(total);

          // Clear the fields.
          $('.num1').val('');
          $('.num2').val('');
          $('.operator').val('');
        }
      });

      // Only allow numbers in the number fields.
      $('.num', context).keydown(function (e) {
        // Allow: backspace, delete, tab, escape, enter and .
        if ($.inArray(e.keyCode, [46, 8, 9, 27, 13, 110, 190]) !== -1 ||
          // Allow: Ctrl+A, Command+A
          (e.keyCode === 65 && (e.ctrlKey === true || e.metaKey === true)) ||
          // Allow: home, end, left, right, down, up
          (e.keyCode >= 35 && e.keyCode <= 40)) {
          // let it happen, don't do anything
          return;
        }
        // Ensure that it is a number and stop the keypress
        if ((e.shiftKey || (e.keyCode < 48 || e.keyCode > 57)) && (e.keyCode < 96 || e.keyCode > 105)) {
          e.preventDefault();
        }
      });
    }
  };

}(jQuery));
