<?php
  // Define plugin for CTools
  $plugin = array(
    'title' => t('Plugin with Extra Styles for Managingnews'),
    'description' => t('Shows different colors & Barchart for MN items'),
    'style_plugin' => array(
      'class' => 'mn_openlayers_extrastyles_plugin', // <-- NOTE!
      'parent' => 'openlayers_style_plugin',
    ),
  );

  drupal_set_message("yes we are a plugin file");
  
  
class mn_openlayers_extrastyles_plugin extends openlayers_style_plugin {

  function options_init() {
    return array(
      'feature_weight' => 2,
      'point_radius_min' => 6,
      'point_radius_max' => 12,
    );
  }

  function options_form($defaults = array()) {
    $form = array();

    $form['point_radius_min'] = array(
      '#type' => 'textfield',
      '#title' => t('Min radius'),
      '#description' => t('Minimum value for the point radius.'),
      '#default_value' => isset($defaults['point_radius_min']) ?
        $defaults['point_radius_min'] : 6,
    );
    $form['point_radius_max'] = array(
      '#type' => 'textfield',
      '#title' => t('Max radius'),
      '#description' => t('Maximum value for the point radius.'),
      '#default_value' => isset($defaults['point_radius_max']) ?
        $defaults['point_radius_max'] : 12,
    );
    $form['feature_weight'] = array(
      '#type' => 'textfield',
      '#title' => t('Feature weight'),
      '#description' => t('Weight of each additional feature for the final point radius.'),
      '#default_value' => isset($defaults['feature_weight']) ?
        $defaults['feature_weight'] : 2,
    );

    return $form;
  }

  
  
  
  // Advertise which style properties we expose support for,
  // and which callback to use for each one
  function get_context_properties() {
    return array(
      'label' => 'getLabel' // <-- NOTE !
    );
  }

  // Send the JS file containing the JavaScript side
  // implementation of the plugin.
  function render() {
    drupal_add_js(drupal_get_path('module', 'mn_openlayers_extrastyles') .
      '/plugins/style_plugin/mn_openlayers_extrastyles_plugin.js');
  }
}
  