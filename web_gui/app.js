// ============================================================================\
// ############################################################################|
// ============================================================================|
//                                                                             |
// CREATE APP
//                                                                             |
// ============================================================================|
// ############################################################################|
// ============================================================================/
var $app = angular.module('app', ['ngRoute']);
var DEBUG = true;








// ============================================================================\
// ############################################################################|
// ============================================================================|
//                                                                             |
// ROUTES
//                                                                             |
// ============================================================================|
// ############################################################################|
// ============================================================================/
$app.config(function($routeProvider) {
	$routeProvider

	// Homepage
	.when('/', {
		templateUrl : 'ide.php',
		controller  : 'editorController'
	})

});
// ----------------------------------------------------------------------------\
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
// ----------------------------------------------------------------------------/





// ============================================================================\
// ############################################################################|
// ============================================================================|
//                                                                             |
// CONTROLLERS
//                                                                             |
// ============================================================================|
// ############################################################################|
// ============================================================================/

// =========================
// Main controller
/*
	Work on all application
*/
// =========================
$app.controller('mainController', ['$scope', function($scope, $routeParams, $route){
	$scope.$route = $route;
	$scope.$routeParams = $routeParams;
}]);


// =========================
// PAGE Editor
// =========================
$app.controller('editorController', function($scope, $http){
	$scope.message = "Perfect! You win!";
	
	$scope.compile = function(){
	    document.getElementById("output").innerHTML = "Loading...";
	    
        var url = "./compile.php?word="+$scope.word+"&stack="+editor.getValue();
        $http.get(url).
          success(function(data, status, headers, config) {
            // this callback will be called asynchronously
            // when the response is available
            console.log(data);
            $scope.output = data.output;
            document.getElementById("output").innerHTML = $scope.output;
          }).
          error(function(data, status, headers, config) {
            // called asynchronously if an error occurs
            // or server returns response with an error status.
            document.getElementById("output").innerHTML = "ERROR! Server does not respond!";
          });
    };
    
    
    var value = "// Stack automata...\n";
    var map = CodeMirror.keyMap.sublime;
    var editor = CodeMirror(document.body.getElementsByTagName("editor")[0], {
        value: value,
        lineNumbers: 40,
        mode: "javascript",
        keyMap: "sublime",
        autoCloseBrackets: true,
        matchBrackets: true,
        showCursorWhenSelecting: true,
        theme: "monokai"
    });
	editor.setSize("100%", "500px");
	editor.on("change", function() {
	    //document.getElementById("code").innerHTML = editor.getValue();
	});
	
	
	// Example content
	var sampleCode = "q1 \n(a, *, a, q1)\n(a, a, a, q1)\n(b, *, =, q2)\n(b, a, -, q2);\n\nq2\n(b, *, =, q2)\n(b, a, =, q2)\n(c, *, =, q3)\n(c, a, =, q3);\n\nq3\n(c, a, -, q3)\n(*, *, =, end);";
	var sampleWord = "aaaabbcccc";
	editor.setValue(sampleCode);
	$scope.word = sampleWord;
    
});
