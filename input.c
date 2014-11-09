	i2c_0: i2c@12C60000 {
		samsung,i2c-sda-delay = <100>;
		samsung,i2c-max-bus-freq = <66000>;
		status = "okay";

		/* Check this better */
		display: touch@4b {
			compatible = "atmel,maxtouch";
			reg = <0x4b>;
			interrupt-parent = <&gpio>;
			interrupts = <512 0>;
		};
	};

	gpio_keys {
		compatible = "gpio-keys";
		#address-cells = <1>;
		#size-cells = <0>;
		autorepeat;

		button@21 {
			label = "GPIO Key UP";
			linux,code = <103>;
			gpios = <&gpio1 0 1>;
		};