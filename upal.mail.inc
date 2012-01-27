<?php
/**
 * smtp_library implementation for upal.
 * copied from simpletest.mail.inc in simpletest module
 * NOTE this is not a module!
 *
 * this file is loaded from DrupalTestCase::setUp
 * and 'drupal_test_email_collector' is used by drupalGetMails() in DrupalTestCase
 */

/**
 * Capture e-mail message during testing.
 *
 * [copied from simpletest.mail.inc]
 * Code copied from TestingMailSystem in mail.sending.inc (Drupal 7). Placed in
 * this file to ensure not loaded until in testing mode, to ensure no conflicts
 * with other implementations like devel.
 *
 * @param $message
 *   An e-mail message.
 */
function drupal_mail_wrapper(array $message) {
  // note: this relies on cache-clear logic in DrupalTestCase::drupalVariableGet, drupalVariableSet to be assert'able in tests.
  $captured_emails = variable_get('drupal_test_email_collector', array());
  $captured_emails[] = $message;
  variable_set('drupal_test_email_collector', $captured_emails);

  /*
  // debug
  watchdog('upal', '@func: added message "@subject" to test email collector. now @count captured emails.',
    array('@func' => __FUNCTION__, '@subject' => $message['subject'], '@count' => count($captured_emails)),
    WATCHDOG_NOTICE);
  */

  return TRUE;
}
