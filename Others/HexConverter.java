public class HexConverter {

    private static final int radixHex = 16;

    /**
     * Calculate the hexadecimal value for a decimal number
     * @param number String
     * @return el value hexadecimal for the input value
     */
    public static String integerToHex(String number){
        return integerToHex(Integer.parseInt(number));
    }

    /**
     * Calculate the hexadecimal value for a decimal number
     * @param number int
     * @return el value hexadecimal for the input value
     */
    public static String integerToHex(int number){
        return Integer.toHexString(number);
    }


    /**
     * Calculate the Decimal value for a hexadecimal number
     * @param hex String hexadecimal
     * @return Decimal value for input
     */
    public static int hexStringToInteger(String hex){
        return Integer.parseInt(hex,radixHex);
    }

    /**
     * Calculate the Decimal value for a hexadecimal number
     * @param hex array of bytes
     * @return Decimal value for input
     */
    public static int hexToInteger(byte[] hex){
        return hexStringToInteger(new String(hex));
    }

}
