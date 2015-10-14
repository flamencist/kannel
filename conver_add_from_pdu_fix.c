static long convert_addr_from_pdu(Octstr *id, Octstr *addr, long ton, long npi, Octstr *alt_addr_charset)
{
    long reason = SMPP_ESME_ROK;

    if (addr == NULL)
        return reason;

    switch(ton) {
        case GSM_ADDR_TON_INTERNATIONAL:
            /*
             * Checks to perform:
             *   1) assume international number has at least 7 chars
             *   2) the whole source addr consist of digits, exception '+' in front
             */
            if (octstr_len(addr) < 7) {
                /* We consider this as a "non-hard" condition, since there "may"
                 * be international numbers routable that are < 7 digits. Think
                 * of 2 digit country code + 3 digit emergency code. */
            } else if (octstr_get_char(addr, 0) == '+' &&
                       !octstr_check_range(addr, 1, 256, gw_isdigit)) {
            } else if (octstr_get_char(addr, 0) != '+' &&
                       !octstr_check_range(addr, 0, 256, gw_isdigit)) {
            }
            /* check if we received leading '00', then remove it*/
            if (octstr_search(addr, octstr_imm("00"), 0) == 0)
                octstr_delete(addr, 0, 2);
            
            /* international, insert '+' if not already here */
            if (octstr_get_char(addr, 0) != '+')
                octstr_insert_char(addr, 0, '+');
            
            break;
        case GSM_ADDR_TON_ALPHANUMERIC:
            if (octstr_len(addr) > 11) {
                /* alphanum sender, max. allowed length is 11 (according to GSM specs) */
            }
            if (alt_addr_charset) {
            }
            break;
        default: /* otherwise don't touch addr, user should handle it */
            break;
    }

error:
    return reason;
}
