<?php

function drush_fsync_values_fsync($site = NULL) {

    $additional_options = array();

    $site_settings = array();

    $site_settings = drush_sitealias_evaluate_path($site,$additional_options , FALSE, "", '');
    
    //drush_print($site);
    //$site_settings = _drush_sitealias_get_record($site);

    drush_print($site_settings);
    if(array_key_exists('site-list', $site_settings)) {
        
        drush_print($site_settings);
    }
    else{
        
        drush_print("No destination_settings found!");
    }
    

    //drush_print(print_r($aliases));
    drush_print("Running values-fsync");
}

function fsync_drush_command() {
  $items = array();

  // The 'values' command
  $items['values-fsync'] = array(
    'description' => "Updates values from values in site-alias.",
    'arguments' => array(
      'site' => 'The site alias to be updated.',
    ),
    /*'options' => array(
      'spreads' => array(
        'description' => 'Comma delimited list of spreads.',
        'example-value' => 'mayonnaise,mustard',
      ),
    ),*/
    'examples' => array(
      'drush vs @source' => 'Updates values from values in site-alias source.',
    ),
    'aliases' => array('vf'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap at all.
  );

  // Commandfiles may also add topics.  These will appear in
  // the list of topics when `drush topic` is executed.
  // To view this topic, run `drush --include=/full/path/to/examples topic`
  /*$items['sandwich-exposition'] = array(
    'description' => 'Ruminations on the true meaning and philosophy of sandwiches.',
    'hidden' => TRUE,
    'topic' => TRUE,
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'callback' => 'drush_print_file',
    'callback arguments' => array(dirname(__FILE__) . '/sandwich-topic.txt'),
  );
  */
  return $items;
}

function fsync_drush_help($section) {
  switch ($section) {
    case 'drush:values-fsync':
      return dt("This command will will update values in sites-alias values.");
    // The 'title' meta item is used to name a group of
    // commands in `drush help`.  If a title is not defined,
    // the default is "All commands in ___", with the
    // specific name of the commandfile (e.g. sandwich).
    // Command files with less than four commands will
    // be placed in the "Other commands" section, _unless_
    // they define a title.  It is therefore preferable
    // to not define a title unless the file defines a lot
    // of commands.
    case 'meta:fsync:title':
      return dt("fsync commands");
    // The 'summary' meta item is displayed in `drush help --filter`,
    // and is used to give a general idea what the commands in this
    // command file do, and what they have in common.
    case 'meta:fsync:summary':
      return dt("Syncs different things for a site-alias.");
  }
}

function drush_fsync_values_fsync_validate() {
  if (drush_is_windows()) {
    // $name = getenv('USERNAME');
    // TODO: implement check for elevated process using w32api
    // as sudo is not available for Windows
    // http://php.net/manual/en/book.w32api.php
    // http://social.msdn.microsoft.com/Forums/en/clr/thread/0957c58c-b30b-4972-a319-015df11b427d
  }
  else {
    //$name = posix_getpwuid(posix_geteuid());
    //if ($name['name'] !== 'root') {
    //    return drush_set_error('MAKE_IT_YOUSELF', dt('What? Make your own sandwich.'));
        
    // }
  }
}

function fsync_values_fsync_complete() {
  return array('values' => array('turkey', 'cheese', 'jelly', 'butter'));
}
