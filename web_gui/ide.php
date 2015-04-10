<div id="ide">
    <div class="container">
        <h1>Stacker <br><small>A stack automata compiler.</small></h1>
        <hr>
        <div class="row">
            <div class="col-lg-6">
                <editor></editor>
            </div>
            <div class="col-lg-6">
                <div class="input-group">
                  <input type="text" class="form-control" ng-model="word" placeholder="Word...">
                  <span class="input-group-btn">
                    <button class="btn btn-default" type="button" ng-click="compile()">Compile</button>
                  </span>
                </div><!-- /input-group -->
                
                <div id="output"></div>
            </div>
        </div>
    </div>
</div>