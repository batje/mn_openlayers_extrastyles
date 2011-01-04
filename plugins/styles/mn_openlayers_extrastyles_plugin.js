

// Define the class constructor
Drupal.openlayers.style_plugin.mn_openlayers_extrastyles_plugin = function (params) {
  this.params = params;
};


// Style plugin class prototype
Drupal.openlayers.style_plugin.mn_openlayers_extrastyles_plugin.prototype = {

  // Style context function
  'getLabel' = function(feature) {
     return feature.attributes.length;
  }

}
